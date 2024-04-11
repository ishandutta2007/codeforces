/*input
1
3
1 1 3
2 2 1
2 3 3

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x, y) ((x >> y) & 1)
#define loop(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define rloop(i, l, r) for (int i = (int)l; i >= (int)r; --i)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() { cout << endl; }
template <typename T, typename... Ts>
void print(const T &value, const Ts &...values) {
  cout << value << ' ', print(values...);
}
#endif
const int N = 1005;

struct DSU {
  vector<int> par, sz;
  void init(int n) {
    par.assign(n + 5, 0);
    sz.assign(n + 5, 1);
    iota(par.begin(), par.end(), 0);
  }
  int find(int x) { return par[x] == x ? x : find(par[x]); }
  bool sameset(int x, int y) { return find(x) == find(y); }
  void uni(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
      return;
    if (sz[x] > sz[y])
      swap(x, y);
    sz[y] += sz[x];
    sz[x] = 0;
    par[x] = y;
  }
} d;

class Solver {
public:
  int a[N][N];
  void operator()() {
    int n;
    cin >> n;
    loop(i, 0, n - 1) {
      loop(j, 0, n - 1) { cin >> a[i][j]; }
    }

    d.init(2 * n);

    auto id = [](int x, int neg) { return x * 2 + neg; };

    loop(i, 0, n - 1) {
      loop(j, i + 1, n - 1) {
        if (a[i][j] == a[j][i])
          continue;
        int is_i = id(i, 0);
        int not_i = id(i, 1);
        int is_j = id(j, 0);
        int not_j = id(j, 1);
        if (a[i][j] < a[j][i]) {
          if (d.sameset(is_i, not_j)) { // must swap
            swap(a[i][j], a[j][i]);
          } else {
            d.uni(is_i, is_j);
            d.uni(not_i, not_j);
          }
        } else {
          if (d.sameset(is_i, is_j)) { // must not swap
          } else {
            swap(a[i][j], a[j][i]);
            d.uni(is_i, not_j);
            d.uni(not_i, is_j);
          }
        }
      }
    }

    loop(i, 0, n - 1) {
      loop(j, 0, n - 1) { cout << a[i][j] << sp; }
      cout << endl;
    }
  }
};

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    Solver solver;
    solver();
  }
}