#include<bits/stdc++.h>
namespace {
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(i,n) for(int i = (int)(n) - 1; i >= 0; i--)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } else return false; }
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  VI a(n);
  struct S { int i, j, x; };
  vector<S> t(q);
  for(auto& [i, j, x]: t) {
    cin >> i >> j >> x;
    i--, j--;
  }
  VI is_zero(n);
  for(auto [i, j, x]: t) {
    is_zero[i] |= ~x;
    is_zero[j] |= ~x;
  }
  for(auto [i, j, x]: t) {
    a[j] |= is_zero[i] & x;
    a[i] |= is_zero[j] & x;
  }
  vector<vector<P>> to(n);
  for (auto [i, j, x]: t) {
    if (i == j) a[i] = x;
    else {
      if (i > j) swap(i, j);
      to[i].emplace_back(j, x);
    }
  }
  rep(i, n) for(auto [j, x]: to[i]) {
    int rest = ~(a[i] | a[j]) & x;
    a[j] |= rest;
  }
  rep(i, n) cout << a[i] << " \n"[i + 1 == n];
}