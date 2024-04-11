// =================================
//   author: memset0
//   date: 2019.07.12 23:56:46
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
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

const int N = 2e5 + 10;
ll ans;
int n, tn, b[N], sum[N << 2];

struct node {
  int x, y;
  inline bool operator<(const node &other) const {
    return y == other.y ? x < other.x : y > other.y;
  }
} a[N];

inline ll calc(int x) {
  return 1ll * x * (x + 1) / 2;
}

void modify(int u, int k, int l, int r) {
  // printf("modify %d %d %d %d\n", u, k, l, r);
  if (l == r) { sum[u] = 1; return; }
  int mid = (l + r) >> 1;
  if (k <= mid) modify(u << 1, k, l, mid);
  else modify(u << 1 | 1, k, mid + 1, r);
  sum[u] = sum[u << 1] + sum[u << 1 | 1];
}

int query(int u, int ql, int qr, int l, int r) {
  if (ql > qr) return 0;
  // printf("query %d %d %d %d %d\n", u, ql, qr, l, r);
  if (ql == l && qr == r) return sum[u];
  int mid = (l + r) >> 1;
  if (qr <= mid) return query(u << 1, ql, qr, l, mid);
  if (ql > mid) return query(u << 1 | 1, ql, qr, mid + 1, r);
  return query(u << 1, ql, mid, l, mid) + query(u << 1 | 1, mid + 1, qr, mid + 1, r);
}

void main() {
  read(n);
  for (int i = 1; i <= n; i++) {
    read(a[i].x), read(a[i].y);
    b[++tn] = a[i].x;
  }
  std::sort(b + 1, b + tn + 1);
  tn = std::unique(b + 1, b + tn + 1) - b - 1;
  std::sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    a[i].x = std::lower_bound(b + 1, b + tn + 1, a[i].x) - b;
  }
  for (int l = 1, r = 1; l <= n; l = r + 1, r = l) {
    while (a[l].y == a[r + 1].y && r + 1 <= n) ++r;
    for (int i = l; i < r; i++) {
      ans -= calc(query(1, a[i].x + 1, a[i + 1].x - 1, 1, tn));
    }
    for (int i = l; i <= r; i++) {
      modify(1, a[i].x, 1, tn);
    }
    ans -= calc(query(1, 1, a[l].x - 1, 1, tn));
    ans -= calc(query(1, a[r].x + 1, tn, 1, tn));
    ans += calc(sum[1]);
    // printf("%d %d %d\n", query(1, 1, a[l].x - 1, 1, tn), query(1, a[r].x + 1, tn, 1, tn), sum[1]);
    // printf("%d %d : %lld\n", l, r, ans);
  }
  print(ans, '\n');
}

} signed main() {
#ifdef memset0
  freopen("1.in", "r", stdin);
#endif
  return ringo::main(), 0;
}