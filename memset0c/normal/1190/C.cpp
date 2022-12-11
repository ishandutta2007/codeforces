// =================================
//   author: memset0
//   date: 2019.07.13 00:18:47
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
char s[N];
bool a[N];
int n, m, flag = true, ans = 3;

void solve() {
  std::set<int> set;
  for (int i = 1; i <= n; i++)
    if (a[i]) {
      set.insert(i);
    }
  if (!set.size()) {
    puts("tokitsukaze");
    exit(0);
  }
  if (set.size() && *--set.end() - *set.begin() + 1 <= m) {
    ans = std::min(ans, 1);
    return;
  }
  // static int t[4];
  // for (int i = 1, max; i + m - 1 <= n; i++) {
  //   auto it = set.upper_bound(i + m - 1);
  //   t[0] = it == set.end() ? -1 : *it;
  //   if (t[0] == -1) t[2] = -1;
  //   else {
  //     t[2] = std::next(it) == set.end() ? -1 : *std::next(it);
  //   }
  //   it = set.lower_bound(i);
  //   t[1] = it == set.begin() ? -1 : *std::prev(it);
  //   if (t[1] == -1) t[3] = -1;
  //   else {
  //     t[3] = std::prev(it) == set.begin() ? -1 : *std::prev(std::prev(it));
  //   }
  //   max = -1;
  //   for (int i = 0; i < 4; i++)
  //     for (int j = i + 1; j < 4; j++) {
  //       max = std::max(max, std::abs(t[i] - t[j]) + 1);
  //     }
  //   if (max <= m) {
      
  //   }
  // }
  for (int i = 1; i + m - 1 <= n && flag; i++) {
    if (*set.begin() >= i) {
      auto it = set.upper_bound(i + m - 1);
      flag &= (*--set.end() - *it + 1) <= m;
    } else if (*--set.end() <= i + m - 1) {
      auto it = --set.lower_bound(i);
      flag &= (*it - *set.begin() + 1) <= m;
    } else {
      flag = false;
    }
  }
}

void main() {
  read(n), read(m), scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) a[i] = s[i] == '1';
  solve();
  for (int i = 1; i <= n; i++) a[i] = s[i] == '0';
  solve();
  if (flag) {
    ans = std::min(ans, 2);
  }
  puts(ans == 1 ? "tokitsukaze" : (ans == 2 ? "quailty" : "once again"));
}

} signed main() {
#ifdef memset0
  freopen("1.in", "r", stdin);
#endif
  return ringo::main(), 0;
}