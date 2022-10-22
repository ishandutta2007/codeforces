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
  int n, m;
  cin >> n >> m;
  VI a(n);
  rep(i, n) cin >> a[i];
  VL sf(n), sb(n);
  rep(i, n - 1) sf[i+1] = sf[i] + max(a[i] - a[i+1], 0);
  rrep(i, n - 1) sb[i] = sb[i+1] + max(a[i+1] - a[i], 0);
  while(m--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    cout << (l < r ? sf[r] - sf[l] : sb[r] - sb[l]) << '\n';
  }
}