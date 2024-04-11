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

template <class S, S (*op)(S, S), S (*e)(), S (*inv)(S)>
struct weighted_union_find {
 public:
  weighted_union_find() : _n(0) {}
  explicit weighted_union_find(int n) : _n(n), parent_or_size(n, -1), weight(n, e()) {}

  int merge(int a, int b, S w) {
    // W(a->b) = Wa^-1 Wb = w
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    int x = leader(a), y = leader(b);
    assert(x != y);
    if (-parent_or_size[x] < -parent_or_size[y]) {
      std::swap(x, y);
      std::swap(a, b);
      w = inv(w);
    }
    // Wa^-1 Wy Wb = w
    // Wy = Wa w Wb^-1
    weight[y] = op(op(weight[a], w), inv(weight[b]));
    parent_or_size[x] += parent_or_size[y];
    parent_or_size[y] = x;
    return x;
  }

  S diff(int a, int b) {
    // W(a->b) = Wa^-1 Wb
    int x = leader(a), y = leader(b);
    assert(x == y);
    return op(inv(weight[a]), weight[b]);
  }

  bool same(int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    return leader(a) == leader(b);
  }

  int leader(int a) {
    assert(0 <= a && a < _n);
    int x = a;
    S w = e();
    while (parent_or_size[x] >= 0) {
      w = op(w, weight[x]);
      x = parent_or_size[x];
    }
    while (a != x) {
      int na = parent_or_size[a];
      S nw = op(inv(weight[a]), w);
      parent_or_size[a] = x;
      weight[a] = w;
      a = na;
      w = nw;
    }
    return x;
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
  // root node: -1 * component size
  // otherwise: parent
  std::vector<int> parent_or_size;
  std::vector<S> weight;
};

int op(int x, int y) { return x ^ y; }
int e() { return 0; }
int inv(int x) { return x; }

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<P>> to(n);
    bool ok = true;
    weighted_union_find<int, op, e, inv> d(n);
    rep(_, n - 1) {
      int x, y, v;
      cin >> x >> y >> v;
      x--, y--;
      to[x].emplace_back(y, v);
      to[y].emplace_back(x, v);
      if (v != -1) {
        int b = __builtin_parity(v);
        d.merge(x, y, b);
      }
    }
    rep(_, m) {
      int a, b, p;
      cin >> a >> b >> p;
      a--, b--;
      if (d.same(a, b)) {
        if (d.diff(a, b) != p) {
          ok = false;
        }
      } else {
        d.merge(a, b, p);
      }
    }
    if (!ok) {
      cout << "NO\n";
      continue;
    }
    rep(i, n) if (!d.same(0, i)) {
      d.merge(0, i, 0);
    }
    cout << "YES\n";
    auto dfs = [&](auto&& self, int u, int p) -> void {
      for(auto [v, c] : to[u]) if (v != p) {
        if (c >= 0) {
          cout << u + 1 << ' ' << v + 1 << ' ' << c << '\n';
        } else {
          cout << u + 1 << ' ' << v + 1 << ' ' << (d.diff(0, u) ^ d.diff(0, v)) << '\n';
        }
        self(self, v, u);
      }
    };
    dfs(dfs, 0, -1);
  }
}