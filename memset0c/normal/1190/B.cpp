// =================================
//   author: memset0
//   date: 2019.07.12 22:37:50
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
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
int n, a[N];
ll ans;

void main() {
  read(n);
  for (int i = 1; i <= n; i++) {
    read(a[i]);
  }
  if (n == 1 && a[1] == 0) {
    puts("cslnb");
    return;
  }
  std::sort(a + 1, a + n + 1);
  int fuck = 0;
  int note = -1;
  for (int i = 1; i < n; i++)
    if (a[i] == a[i + 1]) {
      ++fuck;
      if (fuck == 2) {
        puts("cslnb");
        return;
      } else {
        note = i;
      }
    }
  if (fuck) {
    --a[note];
    ++ans;
    if ((a[note] == a[note - 1] && note > 1) || a[note] < 0) {
      puts("cslnb");
      return;
    }
  }
  a[0] = -1;
  for (int i = 0; i < n; i++) {
    ans += a[i + 1] - a[i] - 1;
    a[i + 1] = a[i] + 1;
  }
  // print(a, 1, n);
  // printf(">> %lld\n", ans);
  puts(ans & 1 ? "sjfnb" : "cslnb");
}

} signed main() {
#ifdef memset0
  freopen("1.in", "r", stdin);
#endif
  return ringo::main(), 0;
}