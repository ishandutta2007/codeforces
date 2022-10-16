#include <stdio.h>
#include <algorithm>

using namespace std;

int t=0, n;
int h[40], a[40];

int main(){
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d%d", &h[i], &a[i]);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      if(h[i] == a[j]) t++;
  printf("%d\n", t);
}