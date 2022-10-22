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

vector<char> memo[(1 << 20) + 100];
bool f(int n, int r) {
  if (!memo[n].empty()) return memo[n][r];
  memo[n].resize(n + 1);
  char now = 0;
  for(int i = n; i >= 0; i--) {
    if (!((n - i) & i)) now ^= 1;
    memo[n][i] = now;
  }
  return memo[n][r];
}

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  VI b(n);
  rep(i, n) cin >> b[i];
  string ans(1 << 20, '0');
  rep(i, n) {
    ll now = 1;
    for(int j = i + 1; j <= n; j++) {
      if (j == i + 1) now *= b[i];
      else {
        if (b[j - 1] >= 20) break;
        now *= 1 << b[j - 1];
        if (now >= (1 << 20)) break;
      }
      int nr = max(i - 1, 0) + max(n - j - 1, 0);
      int kr = max(0, k - (i > 0) - (j < n));
      if (!(0 <= kr && kr <= nr)) continue;
      // cout << i << ' ' << j << ' ' << now << ' ' << nr << ' ' << kr << ' ' << f(nr, kr) << endl;
      ans[now] ^= f(nr, kr);
    }
  }
  while(ans.size() && ans.back() == '0') ans.pop_back();
  if (ans.empty()) ans.push_back('0');
  reverse(all(ans));
  cout << ans << '\n';
}