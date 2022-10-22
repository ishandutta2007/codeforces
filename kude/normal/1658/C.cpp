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
    int n;
    cin >> n;
    VI c(n);
    rep(i, n) cin >> c[i];
    int c1 = 0;
    for(int x: c) c1 += x == 1;
    if (c1 != 1) {
      cout << "NO\n";
      continue;
    }
    auto it = find(all(c), 1);
    rotate(c.begin(), it, c.end());
    int now = 0;
    bool ok = true;
    for(int x: c) {
      if (x > now + 1) {
        ok = false;
        break;
      }
      now = x;
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}