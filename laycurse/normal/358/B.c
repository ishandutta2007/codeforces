#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i, j, k, n;
  static char a[1000000], b[1000000];
  int as, bs;

  as = 0;
  scanf("%d", &n);
  rep(i,n){
    a[as++] = '<';
    a[as++] = '3';
    scanf("%s", a+as);
    as += strlen(a+as);
  }
  a[as++] = '<';
  a[as++] = '3';

  scanf("%s",b);
  bs = strlen(b);

  i = j = 0;
  for(;;){
    if(i==as){ puts("yes"); break; }
    if(j==bs){ puts("no"); break; }
    if(a[i]==b[j]){i++; j++; continue;}
    j++;
  }

  return 0;
}