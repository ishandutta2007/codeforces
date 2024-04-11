#include <stdio.h>

int n;
char s[55];

int main(){
  scanf("%d%s", &n, s);
  char lc = 0;
  int num = 0;
  for(int i = 0; i < n; i++)
    if(s[i] == lc)
      num++;
    else
      lc = s[i];
  printf("%d\n", num);
}