#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define INF 1000000000

int main(){
  int i,j,k,l,m,n;
  int res[1000], q[1000];

  scanf("%d",&n);
  rep(i,n) scanf("%d",&q);
  rep(i,n) res[i]=INF;

  scanf("%d",&m);
  while(m--){
    scanf("%d%d%d",&i,&j,&k); i--; j--;
    if(res[j] > k) res[j] = k;
  }

  k=m=0; rep(i,n) if(res[i]==INF) k++; else m += res[i];
  if(k>1) m=-1;
  printf("%d\n",m);

  return 0;
}