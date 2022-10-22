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
    int n, k;
    cin >> n >> k;
    VI a(n);
    rep(i, n) cin >> a[i];
    if (k >= n) {
      cout << 0 << '\n';
      continue;
    }
    sort(all(a));
    int mex = 0;
    int rest = k;
    rep(i, n - k) {
      if (a[i] == mex - 1) {
        continue;
      } else if (a[i] - mex <= rest) {
        int use = a[i] - mex;
        rest -= use;
        mex = a[i] + 1;
      } else {
        break;
      }
    }
    mex += rest;
    VI d;
    rep(i, n) if (a[i] >= mex) {
      int j = i + 1;
      while(j < n && a[j] == a[i]) j++;
      int cnt = j - i;
      d.emplace_back(cnt);
      i = j - 1;
    }
    sort(rall(d));
    rest = k;
    while(d.size() && d.back() <= rest) {
      rest -= d.back();
      d.pop_back();
    }
    int ans = d.size();
    cout << ans << '\n';
  }
}