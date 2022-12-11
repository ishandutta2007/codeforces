// =================================
//   author: memset0
//   date: 2019.07.12 22:37:50
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define int long long
#define rep(i, l, r) for (int i = (l), i##ed = (r); i <= i##ed; ++i)
#define for_each(i, a) for (size_t i = 0, i##ed = a.size(); i < i##ed; ++i)
namespace ringo {

template <class T> inline void read(T &x) {
  x = 0; char c = getchar(); bool f = 0;
  while (!isdigit(c)) f ^= c == '-', c = getchar();
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  if (f) x = -x;
}
template <class T> inline void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) print(x / 10);
  putchar('0' + x % 10);
}
template <class T> inline void print(T x, char c) { print(x), putchar(c); }
template <class T> inline void print(T a, int l, int r, std::string s = "") {
  if (s != "") std::cout << s << ": ";
  for (int i = l; i <= r; i++) print(a[i], " \n"[i == r]);
}

const int N = 1e5 + 10;
int n, m, k, ans, p[N];

void main() {
  read(n), read(m), read(k);
  for (int i = 1; i <= m; i++) {
    read(p[i]);
  }
  int now = 1, tim = 0;
  while (now <= m) {
    ++ans;
    int cnt = 0;
    int tmp = (p[now] - tim - 1) / k + 1;
    int old_tim = tim;
    while (now <= m && p[now] - old_tim <= k * tmp) {
      ++now;
      ++cnt;
      ++tim;
    }
    // printf("> %d %d\n", tmp, now);
  }
  print(ans, '\n');
}

} signed main() {
#ifdef memset0
  freopen("1.in", "r", stdin);
#endif
  return ringo::main(), 0;
}