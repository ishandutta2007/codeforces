#include<bits/stdc++.h>
namespace {

#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    std::vector<int> parent_or_size;
};

}  // namespace atcoder

using namespace std;
using namespace atcoder;
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
    VI x(n), y(n), timer(n);
    rep(i, n) cin >> x[i] >> y[i] >> timer[i];
    VI ord(n);
    iota(all(ord), 0);
    dsu d(n);
    sort(all(ord), [&](int i, int j) {
      return x[i] < x[j] || (x[i] == x[j] && y[i] < y[j]);
    });
    for(int i = 0; i < n;) {
      int j = i + 1;
      while(j < n && x[ord[i]] == x[ord[j]]) j++;
      for(; i + 1 < j; i++) {
        if (y[ord[i + 1]] - y[ord[i]] <= k) {
          d.merge(ord[i], ord[i + 1]);
        }
      }
      i = j;
    }

    sort(all(ord), [&](int i, int j) {
      return y[i] < y[j] || (y[i] == y[j] && x[i] < x[j]);
    });
    for(int i = 0; i < n;) {
      int j = i + 1;
      while(j < n && y[ord[i]] == y[ord[j]]) j++;
      for(; i + 1 < j; i++) {
        if (x[ord[i + 1]] - x[ord[i]] <= k) {
          d.merge(ord[i], ord[i + 1]);
        }
      }
      i = j;
    }

    VI a;
    for(auto& g: d.groups()) {
      int mn = 1001001001;
      for(int i : g) chmin(mn, timer[i]);
      a.push_back(mn);
    }
    sort(all(a));
    int sz = a.size();
    int ans = sz - 1;
    rep(i, sz) chmin(ans, max(a[i], sz - (i + 1) - 1));
    cout << ans << '\n';
  }
}