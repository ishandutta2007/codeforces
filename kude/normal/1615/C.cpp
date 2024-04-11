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

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    VI a(n), b(n);
    rep(i, n) {
      char c;
      cin >> c;
      a[i] = c - '0';
    }
    rep(i, n) {
      char c;
      cin >> c;
      b[i] = c - '0';
    }
    int cnt[2] = {};
    rep(i, n) if (a[i] != b[i]) {
      cnt[a[i]]++;
    }
    constexpr int INF = 1001001001;
    int ans = INF;
    if (!(cnt[0] + cnt[1] & 1)) {
      if (cnt[0] == cnt[1]) chmin(ans, cnt[0] + cnt[1]);
    }
    cnt[0] = cnt[1] = 0;
    rep(i, n) if (a[i] == b[i]) {
      cnt[a[i]]++;
    }
    if (cnt[0] + cnt[1] & 1) {
      if (cnt[0] + 1 == cnt[1]) chmin(ans, cnt[0] + cnt[1]);
    }
    if (ans == INF) ans = -1;
    cout << ans << '\n';
  }
}