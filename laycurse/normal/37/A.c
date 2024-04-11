#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  int h[1010];
  int res, mx;

  rep(i,1010) h[i]=0;
  scanf("%d",&n);
  rep(i,n) scanf("%d",&k), h[k]++;

  res = 0; mx = -1;
  rep(i,1010){
    if(mx < h[i]) mx = h[i];
    if(h[i]) res++;
  }

  printf("%d %d\n",mx,res);

  return 0;
}