#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
#define M 1000000007

ll pw(ll a,ll b){
  ll r;
  if(b==0) return 1;
  r=pw(a,b/2);
  r=(r*r)%M;
  if(b%2)r=(r*a)%M;
  return r;
}

ll f[210000], fi[210000],res;

int main(){
  int i,j,k,l,m,n;

  f[0]=fi[0]=1;
  REP(i,1,210000){
    f[i] = (f[i-1]*i)%M;
    fi[i] = pw(f[i],M-2);
  }

  while(scanf("%d",&n)==1){
    res = f[2*n-1];
    res = (res * fi[n-1])%M;
    res = (res * fi[n])%M;
    res = (res*2 - n)%M;
    if(res < 0) res += M;
    printf("%d\n",(int)res);
  }

  return 0;
}