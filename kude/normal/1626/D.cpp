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
    VI score(n + 1);
    int now = 1;
    for(int i = 0; i <= n; i++) {
      if (now < i) now *= 2;
      score[i] = now - i;
    }
    VI a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));
    set<int, greater<>> cs{0, n};
    rep(i, n - 1) if (a[i] != a[i + 1]) cs.emplace(i + 1);
    int ans = 1001001001;
    for(int i = 0; i <= n; i++) if (cs.count(i)) {
      for(int p = 1;; p *= 2) {
        int j = *cs.lower_bound(i + p);
        chmin(ans, score[i] + score[j - i] + score[n - j]);
        if (j >= n) break;
      }
    }
    cout << ans << '\n';
  }
}