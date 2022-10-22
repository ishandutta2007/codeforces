#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)


struct segtree{
  int N;
  vector<ll> A;
  segtree(int n){
    N = 1; while(N < n) N *= 2;
    A.assign(N*2,0);
  }
  ll sum(int l, int r){
    l += N; r += N;
    ll ans = 0;
    while(l < r){
      if(l&1) ans += A[l++];
      if(r&1) ans += A[--r];
      l /= 2; r /= 2;
    }
    return ans;
  }
  void add(int p, ll x){
    p += N;
    A[p] += x;
    while(p != 1){
      p /= 2;
      A[p] += x;
    }
  }
};


int N;
vector<ll> A;

const int maxA = 300000;

void testcase(){
  cin >> N;
  A.resize(N);
  rep(i,N) cin >> A[i];
  segtree G(maxA);
  segtree G2(maxA);
  ll sumA = 0;
  ll ans = 0;
  rep(i,N){
    ans += A[i] * i;
    ans -= G.sum(0,A[i]);
    for(int k=A[i]; k<=maxA; k+=A[i]) G.add(k-1,A[i]);
    ans += sumA;
    for(int k=A[i]; k<=maxA; k+=A[i]) ans -= A[i] * G2.sum(k-1,maxA);
    sumA += A[i];
    G2.add(A[i]-1,1);
    if(i) cout << " ";
    cout << ans;
  }
  cout << "\n";
}


int main(){
  testcase();
  return 0;
}

struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_inst;