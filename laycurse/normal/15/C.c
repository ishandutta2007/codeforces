#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

ll get_xor(ll n){
  int i;
  ll res=0, p, rest;

  if(n%4 == 1 || n%4 == 2) res |= 1;
  REP(i,1,62){
    p = (1LL<<(i+1));
    rest = n%p;
    rest -= p/2;
    if(rest<0) continue;
    if((rest+1)%2) res |= (1LL<<i);
  }

  return res;
}

int main(){
  int i,j,k,l,m,n;
  ll res=0, x, t;

  scanf("%d",&n);
  while(n--){
    scanf("%I64lld%I64lld\n",&x,&t);
    res ^= get_xor(x-1);
    res ^= get_xor(x+t-1);
  }

  if(res) puts("tolik"); else puts("bolik");

  return 0;
}