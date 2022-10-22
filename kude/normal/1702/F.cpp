// https://atcoder.jp/contests/abc254/submissions/32300259

#include<bits/stdc++.h>
namespace {
// #pragma GCC diagnostic push
// #pragma GCC diagnostic ignored "-Wunused-function"
// #include<atcoder/all>
// #pragma GCC diagnostic pop
using namespace std;
// using namespace atcoder;
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

bool solve() {
  int n;
  cin >> n;
  vector<P> b(n);
  rep(i, n) {
    int x;
    cin >> x;
    int k;
    if (x) {
      k = __builtin_ctz(x);
      x >>= k;
    } else {
      k = 0;
    }
    b[i] = {x, k};
  }
  sort(rall(b));
  priority_queue<P> q;
  rep(_, n) {
    int x;
    cin >> x;
    if (x) {
      int k = __builtin_ctz(x);
      q.emplace(x >> k, k);
    } else {
      q.emplace(0, 0);
    }
  }
  int ans = 0;
  for(auto [x, k]: b) {
    while(q.top().first > x) {
      auto [y, m] = q.top(); q.pop();
      ans += m + 1;
      y /= 2;
      if (y) {
        m = __builtin_ctz(y);
        q.emplace(y >> m, m);
      } else {
        q.emplace(0, 0);
      }
    }
    if (q.top().first != x) {
      ans = -1;
      break;
    }
    ans += abs(q.top().second - k);
    q.pop();
  }
  // cout << ans << '\n';
  return ans >= 0;
}


} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    cout << (solve() ? "YES\n" : "NO\n");
  }
}