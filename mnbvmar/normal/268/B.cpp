#include <stdio.h>

int tim = 0;
int n;

int main(){
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) tim += (n-i)*i;
  printf("%d\n",tim+n);
}