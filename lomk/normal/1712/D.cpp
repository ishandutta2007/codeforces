/*input
6
3 1
2 4 1
3 2
1 9 84
3 1
10 2 6
3 2
179 17 1000000000
2 1
5 9
2 2
4 2
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
const int INF = 1e9;

class Solver {
public:
  int cal(vector<int> a, int lim) {
    int ret = 0;
    for (auto &it : a) {
      if (2 * it < lim) {
        it = INF;
        ret++;
      }
    }
    loop(i, 0, a.size() - 2) {
      if (min(a[i], a[i + 1]) >= lim)
        return ret;
    }

    loop(i, 0, a.size() - 2) {
      if (min(a[i], INF) >= lim)
        return ret + 1;
      if (min(INF, a[i + 1]) >= lim)
        return ret + 1;
    }
    return ret + 2;
  }

  void operator()() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    loop(i, 0, n - 1) cin >> a[i];

    // print(cal(a, INF));
    // exit(0);
    int l = 1, r = INF;
    while (l != r) {
      int mid = (l + r + 1) / 2;
      if (cal(a, mid) > k)
        r = mid - 1;
      else
        l = mid;
    }
    cout << l << endl;
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