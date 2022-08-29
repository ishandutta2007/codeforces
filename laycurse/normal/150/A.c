#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

int main(){
  ll i,j,k,l,m,n;

  while(scanf("%I64d",&n)==1){
    for(i=2;i*i<=n;i++) if(n%i==0) break;

    if(i*i > n){
      puts("1");
      puts("0");
      continue;
    }

    if(i*i < n && n%(i*i)==0){
      puts("1");
      printf("%I64d\n",i*i);
      continue;
    }

    for(j=i+1;j*j<=n;j++) if(n%j==0) break;
    if(j*j <= n){
      puts("1");
      printf("%I64d\n",i*j);
      continue;
    }

    puts("2");
  }

  return 0;
}