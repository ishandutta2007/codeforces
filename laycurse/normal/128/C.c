#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
#define M 1000000007

ll comb[2100][2100];

int main(){
  int i,j,k,l,m,n;
  int x, y, t;
  int loop;
  ll a, b;

  rep(j,2100) comb[0][j] = 0;
  rep(i,2100) comb[i][0] = 1;
  REP(i,1,2100) REP(j,1,2100) comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % M;

  while(scanf("%d%d%d",&x,&y,&t)==3){
    a = comb[x-1][2*t];
    b = comb[y-1][2*t];
    
    k = (int)((a*b)%M);
    printf("%d\n",k);
  }

  return 0;
}