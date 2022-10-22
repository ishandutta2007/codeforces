#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)


void testcase(){
  int N;
  vector<double> X,Y;
  scanf("%d",&N);
  rep(i,2*N){
    int x,y; scanf("%d%d",&x,&y);
    if(x==0) Y.push_back(abs(y));
    if(y==0) X.push_back(abs(x));
  }
  sort(X.begin(),X.end());
  sort(Y.begin(),Y.end());
  double ans=0.0;
  rep(i,N) ans+=sqrt(X[i]*X[i]+Y[i]*Y[i]);
  printf("%.10f\n",ans);
}

int main(){
  int T; scanf("%d",&T);
  while(T--) testcase();
  return 0;
}