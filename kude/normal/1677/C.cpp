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

vector<vector<int>> cycle_decomposition(const vector<int>& a) {
  const int n = a.size();
  vector<char> visited(n);
  vector<vector<int>> res;
  for(int i = 0; i < n; i++) if (!visited[i]) {
    res.emplace_back();
    auto& vs = res.back();
    int v = i;
    do {
      visited[v] = true;
      vs.push_back(v);
      v = a[v];
    } while (v != i);
  }
  return res;
}

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    VI ca(n), cb(n);
    rep(i, n) cin >> ca[i], ca[i]--;;
    rep(i, n) cin >> cb[i], cb[i]--;
    VI p(n);
    rep(i, n) p[ca[i]] = cb[i];
    ll ans = 0;
    for(auto& c: cycle_decomposition(p)) {
      int k = c.size();
      k >>= 1;
      rep(_, k) {
        ans += 2 * (n - 1);
        n -= 2;
      }
    }
    cout << ans << '\n';
  }
}