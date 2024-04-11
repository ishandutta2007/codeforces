#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using ULL=unsigned long long;
#define rep(i,n) for(int i=0;i<(n);i++)

int solve(){
  int N; cin>>N;
  deque<int> A(N); rep(i,N) cin>>A[i];
  for(int i=0; i<N-2; i++) if((A[i]^A[i+1]) > A[i+2]) return 1;
  for(int i=1; i<N-1; i++) if(A[i-1] > (A[i]^A[i+1])) return 1;
  int ans=1000000000;
  LL X[100][100] = {};
  for(int l=0; l<N; l++) for(int r=l; r<N; r++) X[l][r+1] = X[l][r]^A[r];
  rep(r,N+1) rep(m,r) rep(l,m){
    if(X[l][m] > X[m][r]) ans=min(ans,r-l-2);
  }
  if(ans==1000000000) return -1;
  return ans;
}

int main(){
  cout<<solve()<<endl;
  return 0;
}