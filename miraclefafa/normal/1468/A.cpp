#include <bits/stdc++.h>
using namespace std;

const int N = 500233;
int n, a[N], f[N], t[N], pre[N], ans;
int sta[N], p;
vector<int> V[N];

void ad(int x, int y) {
  for (; x < N; x += x & -x) t[x] = max(t[x], y);
}
int qr(int x) {
  int y = 0;
  for (; x; x -= x & -x) y = max(t[x], y);
  return y;
}
void es(int x) {
  for (; x < N; x += x & -x) t[x] = 0;
}

void Main() {
  scanf("%d", &n);
  ans = 0;
  p = 0;
  for (int i = 1; i <= n; i++) {
    V[i].clear(); f[i] = 0;
    scanf("%d", &a[i]);
    while (p > 0 && a[sta[p]] <= a[i]) --p;
    pre[i] = sta[p];
    sta[++p] = i;
    if (pre[i]) {
      V[pre[i]].push_back(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    f[i] = max(f[i], qr(a[i]) + 1);
    for (auto x : V[i]) {
      f[x] = max(f[x], qr(a[x]) + 2);
    }
    ad(a[i], f[i]);
    ans = max(ans, f[i]);
  }
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++) {
    es(a[i]);
  }
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    Main();
  }
}