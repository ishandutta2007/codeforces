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
    vector<P> a(n);
    rep(i, n) cin >> a[i].first;
    rep(i, n) cin >> a[i].second;
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {
      return a[i] < a[j];
    });
    bool ok = true;
    rep(i, n - 1) if (a[ord[i]].second > a[ord[i+1]].second) {
      ok = false;
    }
    if (!ok) {
      cout << -1 << '\n';
      continue;
    }
    VI x(n);
    rep(i, n) x[ord[i]] = i;
    vector<P> ans;
    rep(i, n) if (x[i] != i) {
      int j = ord[i];
      ans.emplace_back(i, j);
      swap(x[i], x[j]);
      swap(ord[x[i]], ord[x[j]]);
    }
    int m = ans.size();
    cout << m << '\n';
    for(auto [i, j]: ans) cout << i + 1 << ' ' << j + 1 << '\n';
  }
}