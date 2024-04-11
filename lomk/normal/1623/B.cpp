/*input
4
1
1 1
3
1 3
2 3
2 2
6
1 1
3 5
4 4
3 6
4 5
1 6
5
1 5
1 2
4 5
2 2
4 4
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

class TestX {
  int n;
  vector<pair<int, int>> seg;
  set<int> lef[N], rig[N];

public:
  TestX() {}
  void operator()() {
    cin >> n;
    loop(i, 1, n) {
      int l, r;
      cin >> l >> r;
      lef[l].insert(r);
      rig[r].insert(l);
      seg.push_back({l, r});
    }
    sort(seg.begin(), seg.end(), [&](auto &X, auto &Y) {
      int lenX = X.se - X.fi;
      int lenY = Y.se - Y.fi;
      return lenX > lenY;
    });
    for (auto [l, r] : seg) {
      lef[l].erase(r);
      rig[r].erase(l);
      int pick = -1;
      if (lef[l].empty() && rig[r].empty()) {
        pick = l;
      } else if (lef[l].empty()) {
        pick = l;
      } else if (rig[r].empty()) {
        pick = r;
      } else {
        int ml = *lef[l].rbegin();
        pick = ml + 1;
      }
      cout << l << ' ' << r << ' ' << pick << endl;
    }
  }
};

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    TestX test;
    test();
  }
}