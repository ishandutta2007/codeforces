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
    VI b(n);
    rep(i, n) cin >> b[i];
    vector<char> dp(n + 1);
    dp[0] = true;
    rep(i, n) {
      if (dp[i] && i + 1 + b[i] <= n) dp[i+1+b[i]] = true;
      if (i-b[i] >= 0 && dp[i-b[i]]) dp[i+1] = true;
    }
    cout << (dp[n] ? "YES\n" : "NO\n");
  }
}