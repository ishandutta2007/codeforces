#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  char a[101];
  scanf("%s", &a);
  int len = strlen(a);
  char lastchar;
  lastchar = a[0];
  int streak = 1;
  int slppy = 0;
  for(int i = 1; i < len; i++){
    if(a[i] == lastchar){
      streak++;
    } else {
      int c = int((streak + 4)/5);
      slppy += c;
      streak = 1;
      lastchar = a[i];
    }
  }
  int c = int((streak+4)/5);
  slppy += c;
  printf("%d\n", slppy);
  exit(0);
}