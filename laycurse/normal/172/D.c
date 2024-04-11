#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
#define N 10000100
int mn[N];

int main(){
  int i,j,k,l,m,n,a;
  ll res = 0;

  rep(i,N) mn[i] = i;
  for(k=2;k*k<N;k++){
    m = k*k;
    for(i=m,j=1;i<N;i+=m,j++) mn[i] = j;
  }

  scanf("%d%d",&a,&n);
  rep(i,n) res += mn[a+i];

  printf("%I64d\n",res);

  return 0;
}