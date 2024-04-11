#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  int d[2000], s[2000], mx[2000];
  int res = 0, f = 0;

  scanf("%d%d",&n,&k);
  rep(i,n) scanf("%d",d+i);
  rep(i,n) scanf("%d",s+i);

  mx[0] = s[0];
  REP(i,1,n){
    mx[i] = s[i];
    if(mx[i] < mx[i-1]) mx[i] = mx[i-1];
  }

  rep(i,n){
    f += s[i];
    while(f < d[i]) f += mx[i], res += k;
    res += d[i];
    f -= d[i];
  }

  printf("%d\n",res);

  return 0;
}