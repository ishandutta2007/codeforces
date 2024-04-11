#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int N, M;

int main(){
  int i, j, k;
  double res;

  scanf("%d%d",&N,&M);

  res = 1.0 / N;
  if(N*M>1) res += (1 - 1.0/N) / (N*M-1) * (M-1);

  printf("%.10f\n",res);

  return 0;
}