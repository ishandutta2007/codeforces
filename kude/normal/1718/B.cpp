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
  int f[43];
  f[0] = 1;
  f[1] = 2;
  for(int i = 2; i < 43; i++) f[i] = f[i-2] + f[i-1];
  auto solve = [&] {
    int n;
    cin >> n;
    VI a(n);
    rep(i, n) cin >> a[i];
    if (n == 1) return a[0] == 1;
    int used[43]{};
    int last[43]{};
    for(int x: a) {
      rrep(i, 43) {
        if (x >= f[i]) {
          used[i]++;
          x -= f[i];
          if (x == 0) {
            last[i]++;
            break;
          }
        }
      }
    }
    auto check = [&] {
      if (used[0] != 2) return false;
      for(int i = 1; i < 43; i++) {
        if (used[i] >= 2) return false;
        if (!used[i]) {
          for(; i < 43; i++) if (used[i]) return false;
        }
      }
      return true;
    };
    for(int i = 2; i < 43; i += 2) if (used[i] >= 2) {
      if (!last[i]) return false;
      used[i]--;
      i--;
      for(; i >= 0; i -= 2) used[i]++;
      used[0]++;
      return check();
    }
    if (check()) return true;
    rrep(i, 43) if (used[i]) {
      if (i % 2 || !last[i]) return false;
      used[i]--;
      i--;
      for(; i >= 0; i -= 2) used[i]++;
      used[0]++;
      break;
    }
    return check();
  };
  while(tt--) {
    cout << (solve() ? "YES\n" : "NO\n");
  }
}