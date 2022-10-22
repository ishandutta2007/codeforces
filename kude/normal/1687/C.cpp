#include<bits/stdc++.h>
namespace {
using namespace std;
#define private public

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

#undef private
using namespace atcoder;
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

constexpr int MX = 200010;
int a[MX], b[MX];
ll sa[MX], sb[MX];
int l[MX], r[MX];
int tmp[MX];
int mx[MX];
VI qs[MX];
int ready[MX];

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  dsu d(MX);
  VI todo;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, m) cin >> l[i] >> r[i], l[i]--;
    {
      rep(i, n + 1) tmp[i] = 0;
      rep(i, m) tmp[l[i]]++, tmp[r[i]]--;
      bool ok = true;
      int now = 0;
      rep(i, n) {
        now += tmp[i];
        if (a[i] != b[i] && !now) {
          ok = false;
          break;
        }
      }
      if (ok) {
        if (accumulate(a, a + n, 0LL) != accumulate(b, b + n, 0LL)) {
          ok = false;
        }
      }
      if (!ok) {
        cout << "NO\n";
        continue;
      }
    }
    rep(i, n) sa[i+1] = sa[i] + a[i];
    rep(i, n) sb[i+1] = sb[i] + b[i];
    rep(i, n + 1) d.parent_or_size[i] = -1;
    rep(i, n + 1) mx[i] = i;
    rep(i, n) {
      if (sa[i] == sb[i] && sa[i+1] == sb[i+1]) {
        int l = d.merge(i, i + 1);
        mx[l] = i + 1;
      }
    }
    rep(i, n + 1) qs[i].clear();
    rep(j, m) qs[l[j]].emplace_back(j), qs[r[j]].emplace_back(j);
    rep(j, m) ready[j] = 0;
    rep(i, n + 1) if (sa[i] == sb[i]) {
      for(int j: qs[i]) if (++ready[j] == 2) {
        todo.emplace_back(j);
      }
    }
    int done = 0;
    while(todo.size()) {
      int j = todo.back(); todo.pop_back();
      done++;
      for (int i = l[j] + 1; i < r[j]; i++) {
        if (sa[i] == sb[i]) {
          i = mx[d.leader(i)];
          continue;
        }
        sa[i] = sb[i];
        for(int nj: qs[i]) if (++ready[nj] == 2) {
          todo.emplace_back(nj);
        }
        if (i && sa[i-1] == sb[i-1]) {
          int l = d.merge(i-1, i);
          mx[l] = i;
        }
        if (i + 1 <= n && sa[i+1] == sb[i+1]) {
          int l2 = d.leader(i + 1);
          int l = d.merge(i, i + 1);
          i = mx[l] = mx[l2];
        }
      }
    }
    bool ans = done == m;
    cout << (ans ? "YES\n" : "NO\n");
  }
}