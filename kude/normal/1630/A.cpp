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
    int n, k;
    cin >> n >> k;
    int k0 = k;
    n = __builtin_ctz(n);
    int n2 = 1 << n;
    int fb = n2 - 1;
    if (k == fb) {
      if (k == 3) {
        cout << -1 << '\n';
      } else {
        vector<char> inserted(n2);
        int b0 = 1, b1 = 2, b2 = fb ^ 3;
        vector<P> ans{{0, b0}, {b0|b2,b1}, {b2,b1|b2}, {b0|b1, b0|b1|b2}};
        for(int x: {0, b0, b1, b2, b0|b1, b1|b2, b2|b0, b0|b1|b2}) inserted[x] = true;
        for(auto [x, y] : ans) cout << x << ' ' << y << '\n';
        rep(i, n2) if (!inserted[i]) {
          inserted[i] = inserted[fb ^ i] = true;
          cout << i << ' ' <<( i ^ fb ) << '\n';
        }
      }
      continue;
    } else if (k == 0) {
      rep(i, n2 / 2) cout << i << ' ' << (i ^ fb) << '\n';
      continue;
    }
    int t = __builtin_ctz(fb ^ k);
    k = (k & ((1 << t) - 1)) | ((k >> 1) & ~((1 << t) - 1));
    int n22 = n2 / 2;
    int fb2 = n22 - 1;
    int ki = fb2 ^ k;
    vector<P> ans;
    vector<char> inserted(n22);
    if (k == n2 / 2 - 1) {
      ans = {{0, 0}, {k, k}};
      inserted[0] = inserted[k] = true;
    } else {
      ans = {{0, ki}, {ki, k}, {k, fb2}, {fb2, 0}};
      inserted[0] = inserted[ki] = inserted[k] = inserted[fb2] = true;
    }
    rep(i, n22) if (!inserted[i]) {
      int ii = i ^ fb2;
      ans.emplace_back(i, ii);
      ans.emplace_back(ii, i);
      inserted[ii] = inserted[i] = true;
    }
    auto conv = [&](int x) {
      return (x & ((1 << t) - 1)) | ((x & ~((1 << t) - 1)) << 1);
    };
    assert(ans.size() == (1 << n) / 2);
    inserted = vector<char>(1 << n);
    int tot = 0;
    for(auto [x, y]: ans) {
      int cx = conv(x);
      int cy = conv(y) | (1 << t);
      tot += cx & cy;
      assert(!inserted[cx] && !inserted[cy]);
      inserted[cx] = inserted[cy] = true;
      cout << cx << ' ' << cy << '\n';
    }
    assert(tot == k0);
  }
}