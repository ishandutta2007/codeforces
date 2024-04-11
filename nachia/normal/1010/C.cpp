#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

ll GCD(ll a,ll b){ return b ? GCD(b,a%b) : a; }

int N;
ll K;
vector<ll> A;

int main(){
  cin >> N >> K;
  A.resize(N);
  rep(i,N) cin >> A[i];
  ll k = K;
  rep(i,N) k = GCD(k,A[i]);
  cout << (K/k) << "\n";
  for(ll x=0; x<K; x+=k){
    if(x != 0) cout << " ";
    cout << x;
  }
  cout << "\n";
  return 0;
}


struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_inst;