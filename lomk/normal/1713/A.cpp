/*input
3
4
0 -2
1 0
-1 0
0 2
3
0 2
-3 0
0 -1
1
0 0
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

int dis(int l, int r) {
  if (r <= 0)
    return 2 * -l;
  if (l >= 0)
    return 2 * r;
  return (r - l) * 2;
}

class Solver {
public:
  void operator()() {
    int n;
    cin >> n;

    vector<int> allx, ally;
    loop(i, 1, n) {
      int x, y;
      cin >> x >> y;

      allx.push_back(x);
      ally.push_back(y);
    }

    sort(allx.begin(), allx.end());
    sort(ally.begin(), ally.end());

    cout << dis(allx.front(), allx.back()) + dis(ally.front(), ally.back())
         << endl;
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