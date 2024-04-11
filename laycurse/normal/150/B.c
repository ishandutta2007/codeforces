#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define M 1000000007
#define ll long long

ll pw(ll a,ll b, ll md){
  ll r;
  if(!b) return 1;
  r = pw(a,b/2,md);
  r = (r*r)%md;
  if(b%2) r = (r*a)%md;
  return r;
}


int main(){
  int i,j,k,l,m,n;
  ll res;

  while(scanf("%d%d%d",&n,&m,&k)==3){
    if(k == 1 || k > n){
      res = pw(m, n, M);
    } else if(k == n){
      res = pw(m, (n+1)/2, M);
    } else if(k % 2 == 0){
      res = pw(m, 1, M);
    } else {
      if(n > 1) res = pw(m, 2, M);
      else      res = pw(m, 1, M);
    }

    printf("%d\n",(int)res);
  }

  return 0;
}