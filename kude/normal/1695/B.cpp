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
    if (n & 1) {
      cout << "Mike\n";
      continue;
    }
    constexpr int INF = 1001001001;
    int c[2]{INF, INF};
    rep(i, n) chmin(c[i&1], a[i]);
    if (c[0] != c[1]) {
      cout << (c[0] > c[1] ? "Mike\n" : "Joe\n");
      continue;
    }
    rep(i, n) a[i] -= c[0];
    rep(i, n) if (!a[i]) {
      cout << (i & 1 ? "Mike\n" : "Joe\n");
      break;
    }
  }
}