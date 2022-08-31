#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int grundy[100100], mini[100100];

int solve(int n){
  int i,j,k;
  int m;
  int up, down;
  int chk[1000];
  int fin = 0;

  if(grundy[n]>=0) return grundy[n];
  mini[n] = -1;

  rep(i,1000) chk[i]=0;

  for(k=2;;k++){
    up = 2*n - k*k + k;
    down = 2*k;

    if(up < down) break;
    if(up%down) continue;

    m = 0;
    up /= down;
    rep(i,k) m ^= solve(up+i);
    if(m<1000) chk[m] = 1;

    if(m==0 && fin==0) fin=1, mini[n] = k;
  }

  rep(i,1000) if(chk[i]==0) break;
  return grundy[n] = i;
}

int main(){
  int i,j,k,l,m,n;

  rep(i,100100) grundy[i] = -1;

  while(scanf("%d",&n)==1){
    solve(n);
    printf("%d\n",mini[n]);
  }

  return 0;
}