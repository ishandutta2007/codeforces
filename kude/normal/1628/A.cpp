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
    VI a(n);
    rep(i, n) cin >> a[i];
    VI ans;
    VVI idx(n + 2);
    rep(i, n) idx[a[i]].emplace_back(i);
    rep(i, n + 1) reverse(all(idx[i]));
    vector<char> seen(n + 2);
    for(int i = 0; i < n;) {
      if (idx[0].empty()) {
        ans.emplace_back(0);
        i++;
        continue;
      }
      int j = i;
      int nxt = 0;
      while(j < n && idx[nxt].size()) {
        int nj = idx[nxt].back() + 1;
        while(j < nj) {
          idx[a[j]].pop_back();
          seen[a[j++]] = true;
        }
        while(seen[nxt]) nxt++;
      }
      ans.emplace_back(nxt);
      while(i < j) seen[a[i++]] = false;
    }
    int sz = ans.size();
    cout << sz << '\n';
    rep(i, sz) cout << ans[i] << " \n"[i + 1 == sz];
  }
}