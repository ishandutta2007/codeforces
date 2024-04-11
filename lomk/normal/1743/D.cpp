/*input
4
0000


7
1110010

5
11010

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
const int N = 1e6;

bitset<N> OR(bitset<N> &s, bitset<N> &t) { return (s | t); }

template <std::size_t N>
bool operator<(const std::bitset<N> &x, const std::bitset<N> &y) {
  for (int i = N - 1; i >= 0; i--) {
    if (x[i] ^ y[i])
      return y[i];
  }
  return false;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  bitset<N> s;

  cin >> n;
  cin >> s;
  // print(s);

  auto ans = s;
  const int total = 15;
  loop(start, 0, total) {
    int len = 0;
    bitset<N> t;
    loop(i, start, n - 1) {
      t[len] = s[i];
      len++;
      if (n - len <= total) {
        auto rec = OR(s, t);
        if (ans < rec)
          ans = rec;
      }
    }
  }

  int lead = -1;
  rloop(i, N-1, 0) {
    if (ans[i] != 0) {
      lead = i;
      break;
    }
  }
  if (lead == -1)
    cout << 0 << endl;
  else {
    rloop(i,lead,0) cout << ans[i];
    cout << endl;
  }
}