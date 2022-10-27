/*input
4
3
1 1 2
4
4 4 4 4
1
1
5
1 3 2 1 1

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
// const int N =;

class TestX {
public:
  bool check(int k, multiset<int> a) {
    loop(turn, 1, k) {
      if (a.empty())
        return false;
      int lim = k - turn + 1;
      auto iter = a.upper_bound(lim);
      if (iter == a.begin())
        return false;
      --iter;
      a.erase(iter);

      if (!a.empty()) {
        auto val = *a.begin();
        a.erase(a.begin());
        val += k - turn + 1;
        a.insert(val);
      }
    }
    return true;
  }

  void operator()() {
    int n;
    multiset<int> a;
    cin >> n;
    loop(i, 1, n) {
      int t;
      cin >> t;
      a.insert(t);
    }

    int l = 0, r = n;
    while (l != r) {
      int mid = (l + r + 1) / 2;
      if (check(mid, a))
        l = mid;
      else
        r = mid - 1;
    }
    cout << l << endl;
    // ceil n / 2

    //
  }
};

int T;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> T;
  while (T--) {
    TestX test;
    test();
  }
}