/*input
1
5
1 4 4 3 3
3
4
2 3 5 4
3
1 2 3
4
3 1 3 2
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

class Solver {
public:
  void operator()() {
    int n;
    cin >> n;
    vector<pair<int, int>> ele;
    loop(i, 0, n - 1) {
      int t;
      cin >> t;
      ele.push_back({t, i});
    }
    sort(ele.begin(), ele.end(), greater<pair<int, int>>());

    int mn = 1e9, mx = 0;
    for (int i = 0; i < n; i++) {
      int lastI;
      for (int j = i; j < n; j++) {
        if (ele[j].fi == ele[i].fi) {
          mn = min(mn, ele[j].se);
          mx = max(mx, ele[j].se);
          lastI = j;
        } else
          break;
      }

      if (mx - mn + 1 != lastI + 1) {
        cout << "NO" << endl;
        return;
      }
      i = lastI;
    }
    cout << "YES" << endl;
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