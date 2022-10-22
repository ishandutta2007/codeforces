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

constexpr int MX = 500100;
int col[MX];

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  rep(i, MX) col[i] = i;
  int q;
  cin >> q;
  struct Q {
    int t, x, y;
  };
  vector<Q> qs(q);
  for(auto& [t, x, y] : qs) {
    cin >> t;
    if (t == 1) cin >> x;
    else cin >> x >> y;
  }
  VI ans;
  reverse(all(qs));
  for(auto [t, x, y] : qs) {
    if (t == 1) {
      ans.emplace_back(col[x]);
    } else {
      col[x] = col[y];
    }
  }
  reverse(all(ans));
  int sz = ans.size();
  rep(i, sz) cout << ans[i] << " \n"[i + 1 == sz];
}