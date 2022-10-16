/*input
4
4
1 2 10 100
4
100 100 100 1
5
5 1 1 1 8
6
1 2 3 4 5 6
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
  vector<int> a;

public:
  TestX() {}

  bool check(int mid) const {
    vector<int> b = a;
    rloop(i, b.size() - 1, 2) {
      int rem = (min(a[i], b[i] - mid)) / 3;
      b[i - 1] += rem;
      b[i - 2] += 2 * rem;
    }

    vector<int> c = a;
    loop(i, 2, c.size() - 1) {
      int rem = min(c[i], b[i] - mid) / 3;
      c[i - 1] += rem;
      c[i - 2] += 2 * rem;
      //   print(i, rem);
    }
    for (auto it : c)
      if (it < mid)
        return false;
    return true;
  }

  void operator()() {
    cin >> n;
    loop(i, 1, n) {
      int t;
      cin >> t;
      a.push_back(t);
    }
    int l = 1, r = 1e9;
    while (l != r) {
      int mid = (l + r + 1) / 2;
      if (check(mid))
        l = mid;
      else
        r = mid - 1;
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
    TestX test;
    test();
  }
}