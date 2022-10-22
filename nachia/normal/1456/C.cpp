#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using ULL=unsigned long long;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  int N,K; scanf("%d%d",&N,&K); K++;
  vector<LL> A(N); rep(i,N) scanf("%lld",&A[i]);
  sort(A.begin(),A.end());
  vector<LL> S(N+1); for(int i=N-1; i>=0; i--) S[i]=S[i+1]+A[i];
  vector<LL> Dec(N+1); rep(i,N) Dec[i+1] = Dec[i]+A[i]*(i/K);
  vector<LL> Inc(N+1); for(int i=N-1; i>=0; i--){ Inc[i]=Inc[i+1]+S[i+1]; }
  rep(i,N+1) Inc[i] += S[i]*(i/K);

  LL ans=-1000000000000000000;
  rep(i,N+1) ans=max(ans,Inc[i]+Dec[i]);
  cout<<ans<<endl;
  return 0;
}