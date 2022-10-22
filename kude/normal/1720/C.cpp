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
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    rep(i, n) cin >> a[i];
    int c = 0;
    rep(i, n) rep(j, m) c += a[i][j] - '0';
    if (c == n * m) {
      cout << c - 2 << '\n';
      continue;
    }
    bool ok = false;
    rep(i, n - 1) rep(j, m - 1) {
      int cnt = 0;
      rep(k, 2) rep(l, 2) cnt += a[i+k][j+l] - '0';
      if (cnt <= 2) ok = true;
    }
    cout << (ok ? c : c - 1) << '\n';
  }
}