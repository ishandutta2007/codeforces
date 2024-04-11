/*input
3
3
0 1 0
5
0 0 1 1 1
6
1 1 1 0 0 1

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

const int mod = 998244353;

#define pow binPow
int binPow(int a, long long q) {
  int ret = 1;
  while (q) {
    if (q % 2)
      ret = 1LL * ret * a % mod;
    a = 1LL * a * a % mod;
    q /= 2;
  }
  return ret;
}

class TestX {
public:
  int n;
  int n0 = 0, n1 = 0;
  int maxK = 0;
  vector<int> a;

  int C2x(int t) { return t * (t - 1) / 2; }

  void countN0N1() {
    for (auto it : a)
      if (it == 0)
        n0++;
      else
        n1++;
    rloop(i, n - 1, n - n1) if (a[i] == 0) maxK++;
  }

  void operator()() {
    cin >> n;
    a = vector<int>(n, 0);
    for (auto &it : a)
      cin >> it;

    countN0N1();
    if (maxK == 0) {
      cout << 0 << endl;
      return;
    }
    int sum2 = 0;
    loop(i, 1, maxK) {
      sum2 = (sum2 + C2x(n) % mod * binPow(i * i % mod, mod - 2)) % mod;
    }

    cout << sum2 % mod << endl;
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