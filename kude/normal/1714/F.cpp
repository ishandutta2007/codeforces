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
    int d1, d2, d3;
    cin >> d1 >> d2 >> d3;
    int xyz = d1 + d2 + d3;
    if (xyz & 1) {
      cout << "NO\n";
      continue;
    }
    xyz /= 2;
    if (1 + xyz > n) {
      cout << "NO\n";
      continue;
    }
    int x = xyz - d2, y = xyz - d3, z = xyz - d1;
    if (x < 0 || y < 0 || z < 0) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    int v = 1;
    int nxt = 4;
    rep(i, x) {
      if (i == x - 1) {
        if (!y) {
          cout << v << ' ' << 2 << '\n';
          v = 2;
          continue;
        } else if (!z) {
          cout << v << ' ' << 3 << '\n';
          v = 3;
          continue;
        }
      }
      cout << v << ' ' << nxt << '\n';
      v = nxt++;
    }
    int lca = v;
    rep(i, y) {
      if (i == y - 1) {
        cout << v << ' ' << 2 << '\n';
      } else {
        cout << v << ' ' << nxt << '\n';
        v = nxt++;
      }
    }
    v = lca;
    rep(i, z) {
      if (i == z - 1) {
        cout << v << ' ' << 3 << '\n';
      } else {
        cout << v << ' ' << nxt << '\n';
        v = nxt++;
      }
    }
    while(nxt <= n) cout << 1 << ' ' << nxt++ << '\n';
  }
}