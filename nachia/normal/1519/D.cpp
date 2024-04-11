#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
using namespace std;

struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_instance;

void solve(){
  int N; cin>>N;
  vector<ll> A(N);
  for(int i=0; i<N; i++) cin>>A[i];
  vector<ll> B(N);
  for(int i=0; i<N; i++) cin>>B[i];
  vector<ll> SumAB(N+1,0);
  for(int i=0; i<N; i++) SumAB[i+1] = SumAB[i] + A[i] * B[i];
  ll ans = 0;
  for(int d=1; d<=2*N; d++){
    vector<ll> X(N+1,0);
    for(int j=0; j<N; j++) if(0<=d-1-j) if(d-1-j<N) X[j+1] = A[j] * B[d-1-j];
    for(int j=0; j<N; j++) X[j+1] += X[j];
    for(int r=0; r<=N; r++){
      int l = d-r;
      if(l < 0) continue;
      if(l >= N) continue;
      if(l >= r) continue;
      ll tmp = 0;
      tmp += SumAB[l];
      tmp += SumAB[N] - SumAB[r];
      tmp += X[r] - X[l];
      ans = max(ans,tmp);
    }
  }
  
  cout<<ans<<"\n";
}

int main(){
  solve();
  return 0;
}