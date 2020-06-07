/*
 *      Copyright (C) 2020 peak3d
 *      http://www.peak3d.de
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  <http://www.gnu.org/licenses/>.
 *
 */

#include "DASHTree.h"
#include "../log.h"

void Log(const LogLevel loglevel, const char* format, ...)
{
}

bool adaptive::AdaptiveTree::download(const char* url,
                                      const std::map<std::string, std::string>& manifestHeaders,
                                      void* opaque,
                                      bool scanEffectiveURL)
{
  FILE* f = fopen(url, "rb");
  if (!f)
    return false;

   // read the file
  static const unsigned int CHUNKSIZE = 16384;
  char buf[CHUNKSIZE];
  size_t nbRead;

  while ((nbRead = fread(buf, 1, CHUNKSIZE, f)) > 0 && ~nbRead && write_data(buf, nbRead, opaque))
    ;

  fclose(f);

  SortTree();

  return nbRead == 0;
}

int main(int argc, char** argv)
{
  if (argc < 2)
  {
    printf("Usage: <filename>)");
    exit(1);
  }

  adaptive::DASHTree tree;
  if (!tree.open(argv[1], ""))
  {
    printf("open() failed");
    exit(-1);
  }

  //Write the raw structure of the tree

  return 0;
}
