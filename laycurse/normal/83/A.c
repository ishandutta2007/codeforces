#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

int main(){
  int i,j,k,l,m,n;
  int in[120000];
  ll res, add;

  while(scanf("%d",&n)==1){
    rep(i,n) scanf("%d",in+i);
    res = 0;
    for(i=0;i<n;){
      j=i+1;
      while(j<n && in[j]==in[i]) j++;
      add = j-i;
      res += add*(add+1)/2;
      i=j;
    }
    printf("%I64d\n",res);
  }

  return 0;
}