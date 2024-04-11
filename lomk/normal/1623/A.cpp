/*input
5
10 10 6 1 2 8
10 10 9 9 1 1
9 8 5 6 2 1
6 9 2 2 5 8
2 2 1 1 2 1
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

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int n, m, rb, cb, rd, cd;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    int x = 1, y = 1;
    for (int i = 0;; i++) {
      if (rb == rd || cb == cd) {
        cout << i << endl;
        break;
      }
      int nrb = rb + x;
      int ncb = cb + y;
      if (nrb < 1 || nrb > n)
        x = -x;
      if (ncb < 1 || ncb > m)
        y = -y;
      rb = rb + x;
      cb = cb + y;
      //   print(rb, cb);
    }
  }
}