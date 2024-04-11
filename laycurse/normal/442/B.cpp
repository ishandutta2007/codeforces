#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int N; double P[200];

int main(){
  int i, j, k;
  double res, zero, one;

  scanf("%d",&N);
  rep(i,N) scanf("%lf",P+i);
  sort(P, P+N);

  res = 0;
  rep(i,N+1) rep(j,N+1) if(i+j <= N){
    zero = 1;
    one = 0;

    rep(k,i){
      one = one * (1-P[k]) + zero * P[k];
      zero = zero * (1-P[k]);
    }
    rep(k,j){
      one = one * (1-P[N-1-k]) + zero * P[N-1-k];
      zero = zero * (1-P[N-1-k]);
    }

    res = max(res, one);
  }

  printf("%.15f\n",res);

  return 0;
}