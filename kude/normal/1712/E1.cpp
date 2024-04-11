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

VI divs[400001];
VI imemo[200001], kmemo[200001];

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for(int d = 1; d <= 400001; d++) {
    for(int i = d; i <= 400000; i += d) {
      divs[i].emplace_back(d);
    }
  }
  for(int k = 1; k <= 200000; k++) {
    int sz = divs[2*k].size();
    imemo[k].resize(400000 / k + 1);
    kmemo[k].resize(sz);
    rep(jj, sz - 2) rep(ii, jj) {
      int i = divs[2*k][ii], j = divs[2*k][jj];
      if (i + j <= k && (k % i || k % j)) continue;
      imemo[i][2*k/i]++;
      kmemo[k][ii]++;
    }
  }
  for(int i = 1; i <= 200000; i++) {
    int sz = 400000 / i + 1;
    rep(kk, sz - 1) imemo[i][kk+1] += imemo[i][kk];
  }
  for(int k = 1; k <= 200000; k++) {
    int sz = divs[2*k].size();
    rrep(ii, sz-1) kmemo[k][ii] += kmemo[k][ii+1];
  }
  int tt;
  cin >> tt;
  VL ans(tt);
  constexpr int B = 450;
  struct Q {
    int l, r, i;
    bool operator<(const Q& rhs) const {
      int b = r / B, brhs = rhs.r / B;
      if (b != brhs) return b < brhs;
      return l < rhs.l;
    }
  };
  vector<Q> qs(tt);
  rep(i, tt) {
    int l, r;
    cin >> l >> r;
    qs[i] = {l, r + 1, i};
  }
  sort(all(qs));
  auto get_i = [&](int i, int r) {
    return imemo[i][2 * (r - 1) / i];
  };
  auto get_k = [&](int k, int l) {
    int s = lower_bound(all(divs[2*k]), l) - divs[2*k].begin();
    return kmemo[k][s];
  };
  ll now = 0;
  int l = 1, r = 1;
  for(auto [li, ri, qi]: qs) {
    while(l > li) now += get_i(--l, r);
    while(r < ri) now += get_k(r++, l);
    while(l < li) now -= get_i(l++, r);
    while(r > ri) now -= get_k(--r, l);
    int cnt = r - l;
    ans[qi] = (ll)cnt * (cnt - 1) * (cnt - 2) / 6 - now;
  }
  rep(i, tt) cout << ans[i] << '\n';
}