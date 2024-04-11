#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int ab(int x){if(x<0) return -x; return x;}

int main(){
  int i,j,k,l,m,n;
  char a[3],b[3];

  scanf("%s%s",a,b);

  i=ab(a[0]-b[0]); j=ab(a[1]-b[1]);
  if(i<j) i=j;
  printf("%d\n",i);

  while(a[0]!=b[0] || a[1]!=b[1]){
    if(a[0]>b[0]) putchar('L'), a[0]--;
    if(a[0]<b[0]) putchar('R'), a[0]++;
    if(a[1]>b[1]) putchar('D'), a[1]--;
    if(a[1]<b[1]) putchar('U'), a[1]++;
    puts("");
  }

  return 0;
}