#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int bit(int n){
  int res=0;
  while(n) res++, n&=(n-1);
  return res;
}

int main(){
  int i,j,k,l,m,n,opt=20;
  char in[9][10];

  rep(i,8) scanf("%s",in[i]);
  rep(n,1<<16){
    m=bit(n); if(m>=opt) continue;
    k=0;
    rep(i,8) rep(j,8){
      if(in[i][j]=='B') if( (n&(1<<i))|| (n&(1<<(8+j))) ) continue;
      if(in[i][j]=='W') if(!(n&(1<<i))&&!(n&(1<<(8+j))) ) continue;
      k++;
    }
    if(k==0) opt=m;
  }
  printf("%d\n",opt);

  return 0;
}