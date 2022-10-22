#include<bits/stdc++.h>
namespace {
using namespace std;
#define rep(i,n)for (int i = 0; i < int(n); ++i)
#define rrep(i,n)for (int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

constexpr int MX = 5e6 + 1;
int hist[MX];
int xhist[MX];

ll dp[MX];

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  rep(_, n) {
    int x;
    cin >> x;
    xhist[x]++;
  }
  rep(x, MX) if (xhist[x]) {
    const int cnt = xhist[x];
    int d = 1;
    for(; d * d < x; d++) {
      if (x % d == 0) {
        hist[d] += cnt;
        hist[x / d] += cnt;
      }
    }
    if (d * d == x) hist[d] += cnt;
  }
  int i = MX - 1;
  for(;; i--) {
    if (hist[i] == n) {
      dp[i] = (ll) n * i;
      break;
    }
  }
  for(; i < MX; i++) {
    for(int j = 2 * i; j < MX; j += i) {
      chmax(dp[j], dp[i] + ll(j - i) * hist[j]);
    }
  }
  ll ans = *max_element(dp, dp + MX);
  cout << ans << '\n';
}