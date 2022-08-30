#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
int bit[817637];

int bit_count(int n){
  int res=0;
  while(n){
    res += bit[n%(1<<16)];
    n >>= 16;
  }
  return res;
}

int is_in(ll dx,ll dy,ll r){
  if(r*r < dx*dx + dy*dy) return 1;
  return 0;
}

int main(){
  int i,j,k,l,m,n,q,M;
  int x[1200], y[1200];
  int r[1200], cx[1200], cy[1200];
  int in[1200][40];
  int res;

  rep(i,1<<16){
    k=0; m=i;
    while(m) m&=(m-1), k++;
    bit[i]=k;
  }

  scanf("%d%d%d",&n,&m,&q);
  M = m/30 + 2;
  rep(i,n) rep(j,M) in[i][j]=0;

  rep(i,n) scanf("%d%d",x+i,y+i);
  rep(i,m) scanf("%d%d%d",r+i,cx+i,cy+i);

  rep(i,n) rep(j,m) if(is_in(x[i]-cx[j],y[i]-cy[j],r[j])){
    in[i][j/30] |= (1<<(j%30));
  }

  while(q--){
    scanf("%d%d",&i,&j); i--; j--;
    res=0;
    rep(k,M) res += bit_count(in[i][k]^in[j][k]);
    printf("%d\n",res);
  }

  return 0;
}