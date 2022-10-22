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
  int n, m, q;
  cin >> n >> m >> q;
  VI a(n), b(m);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];
  VI c = a;
  c.insert(c.end(), all(b));
  sort(all(c));
  const int nm = n + m;
  vector<P> evs;
  rep(i, nm - 1) evs.emplace_back(c[i + 1] - c[i], i);
  sort(rall(evs));
  dsu d(nm);
  VI idx_mx(nm);
  VI cnt(nm);
  rep(i, nm) idx_mx[i] = i;
  for(int ai: a) {
    int idx = --upper_bound(all(c), ai) - c.begin();
    cnt[idx]++;
  }
  VL s(nm + 1);
  rep(i, nm) s[i + 1] = s[i] + c[i];
  ll now = 0;
  rep(i, nm) {
    now += s[i + 1] - s[i + 1 - cnt[i]];
  }

  VL ans(q);
  vector<P> qs;
  rep(i, q) {
    int k;
    cin >> k;
    qs.emplace_back(k, i);
  }
  sort(all(qs));
  for(auto [k, i] : qs) {
    while(evs.size() && evs.back().first <= k) {
      auto [_, p] = evs.back(); evs.pop_back();
      int q = p + 1;
      int lp = d.leader(p), lq = d.leader(q);
      for(int l : {lp, lq}) {
        int imx = idx_mx[l];
        now -= s[imx + 1] - s[imx + 1 - cnt[l]];
      }
      int l = d.merge(lp, lq);
      cnt[l] = cnt[lp] + cnt[lq];
      idx_mx[l] = idx_mx[lq];

      int imx = idx_mx[l];
      now += s[imx + 1] - s[imx + 1 - cnt[l]];
    }
    ans[i] = now;
  }
  rep(i, q) cout << ans[i] << '\n';
}