#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 200233;
int n, m, a[N], k[N], ans[N];
ll s[N];
vector<pair<int, int> > f;

int mx[N<<2];
void upd(int p, int l, int r, int ql, int qr, int x) {
  if (l == ql && r == qr) {
    mx[p] = max(mx[p], x);
    return;
  }
  int mid = (l + r) >> 1;
  if (qr <= mid) upd(p << 1, l, mid, ql, qr, x);
  else if (ql > mid) upd(p << 1 | 1, mid + 1, r, ql, qr, x);
  else upd(p << 1, l, mid, ql, mid, x),
    upd(p << 1 | 1, mid + 1, r, mid + 1, qr, x);
}
void pd(int p, int l, int r) {
  if (l == r) ans[l] = mx[p];
  else {
    mx[p << 1] = max(mx[p << 1], mx[p]);
    mx[p << 1 | 1] = max(mx[p << 1 | 1], mx[p]);
    int mid = (l + r) >> 1;
    pd(p << 1, l, mid);
    pd(p << 1 | 1, mid + 1, r);
  }
}

bool check(int x, int y1, int y2) {
  return s[y2] - s[y1] <= (ll) k[x] * (y2 - y1);
}
void update(int l, int r, int x) {
  upd(1, 1, m, l, r, x);
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
  for (int i = 1; i <= m; i++) scanf("%d", &k[i]);
  f.push_back(make_pair(1, 0));
  for (int i = 1; i <= n - 1; i++) {
    int r = m;
    while (!f.empty()) {
      if (check(f.back().first, f.back().second, i)) {
        update(f.back().first, r, i - f.back().second - 1);
        r = f.back().first - 1;
        f.pop_back();
      } else {
        int L = f.back().first, R = r + 1, y = f.back().second, l = L;
        while (L < R) {
          int mid = (L + R) >> 1;
          if (check(mid, y, i)) {
            R = mid;
          } else {
            L = mid + 1;
          }
        }
        if (L != r + 1) {
          f.pop_back();
          f.push_back(make_pair(l, y));
          update(L, r, i - y - 1);
          f.push_back(make_pair(L, i));
        } else if (r != m) {
          f.push_back(make_pair(r + 1, i));
        }
        break;
      }
    }
    if (f.empty()) f.push_back(make_pair(1, i));
  }
  int r = m;
  while (!f.empty()) {
    update(f.back().first, r, n - f.back().second - 1);
    r = f.back().first - 1;
    f.pop_back();
  }
  pd(1, 1, m);
  for (int i = 1; i <= m; i++) printf("%d ", ans[i]);
}