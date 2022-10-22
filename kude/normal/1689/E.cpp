#include<bits/stdc++.h>
namespace {
using namespace std;

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

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int ans = 0;
    VI a(n);
    rep(i, n) cin >> a[i];
    rep(i, n) if (a[i] == 0) {
      a[i]++;
      ans++;
    }
    auto chk = [&] {
      dsu d(n);
      int idx[30];
      rep(i, 30) idx[i] = -1;
      rep(i, n) {
        int x = a[i];
        rep(k, 30) if (x >> k & 1) {
          if (idx[k] == -1) {
            idx[k] = i;
          } else {
            d.merge(i, idx[k]);
          }
        }
      }
      rep(i, n) if (!d.same(0, i)) return false;
      return true;
    };
    if (!chk()) {
      bool ok = false;
      rep(i, n) {
        a[i]--;
        if (chk()) {
          ok = true;
          ans++;
          break;
        }
        a[i] += 2;
        if (chk()) {
          ok = true;
          ans++;
          break;
        }
        a[i]--;
      }
      if (!ok) {
        int mxlsb = -1;
        rep(i, n) chmax(mxlsb, __builtin_ctz(a[i]));
        VI idxs;
        rep(i, n) if (__builtin_ctz(a[i]) == mxlsb) {
          idxs.emplace_back(i);
        }
        assert(idxs.size() >= 2);
        a[idxs[0]]--;
        a[idxs[1]]++;
        ans += 2;
      }
    }
    cout << ans << '\n';
    rep(i, n) cout << a[i] << " \n"[i + 1 == n];
  }
}