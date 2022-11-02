#include <bits/stdc++.h>

using namespace std;

const int LIM = 31;
const int N = 111;
const int M = 1000;

typedef unsigned int ui;
typedef pair<int, int> pii;

int n;
pii a[N];
int b[N];
int tb[N];
int g[M][M];

int ABS(int a) {
  return a > 0 ? a : -a;
}

int calc(int *other) {
  int res = 0;
  for (int i = 0; i < n; i++)
    res += ABS(other[i] - a[i].first);
  return res;
}

int cnt = 0;

void update(ui mask) {
  if (mask == 0)
    return;
  int sz = 0;
  for (int i = 0; i < LIM; i++)
    if (mask & (1 << i))
      tb[sz++] = i;
  int last = tb[sz - 1];
  while (sz < n) {
    for (;;) {
      bool ok = true;
      for (int i = 0; i < sz && ok; i++)
        if (g[last][tb[i]] != 1)
          ok = false;
      if (ok)
        break;
      else
        last++;
    }
    tb[sz++] = last;
    last++;
  }
  for (int sft = 0; sft < n; sft++) {
    if (calc(tb) < calc(b))
      copy(tb, tb + n, b);
    for (int i = n - 1; i > 0; i--)
      tb[i] = tb[i - 1];
    tb[0] = 1;
  }
}

void go(ui mask, int last) {
  if (last == LIM) {
    update(mask);
    return;
  }
  for (int i = last; i < LIM; i++) {
    bool ok = true;
    for (int j = 1; j < last && ok; j++)
      if ((mask & (1 << j)) && g[i][j] != 1)
        ok = false;
    if (!ok)
      continue;
    go(mask | (1 << i), i + 1);
  }
  go(mask, LIM);
}

int main() {
  ios_base::sync_with_stdio(0);

  for (int x = 1; x < M; x++)
    for (int y = 1; y < M; y++)
      g[x][y] = __gcd(x, y);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a, a + n);
  fill(b, b + n, 1);
  go(0, 1);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (a[j].second == i)
        cout << b[j] << " ";

  return 0;
}