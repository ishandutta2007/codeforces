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
    VI a(n);
    rep(i, n) cin >> a[i];
    if (n % 2) {
      cout << "NO\n";
      continue;
    }
    sort(all(a));
    int n2 = n / 2;
    VI b(n);
    rep(i, n2) {
      b[2 * i] = a[i];
      b[2 * i + 1] = a[n2 + i];
    }
    bool ok = true;
    rep(i, n) {
      if (i % 2 == 0) {
        if (b[i] >= b[i+1]) {
          ok = false;
          break;
        }
      } else {
        if (b[i] <= b[(i+1) % n]) {
          ok = false;
          break;
        }
      }
    }
    if (ok) {
      cout << "YES\n";
      rep(i, n) cout << b[i] << " \n"[i + 1 == n];
    } else {
      cout << "NO\n";
    }
  }
}