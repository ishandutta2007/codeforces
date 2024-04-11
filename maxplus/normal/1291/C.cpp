#include<iostream>

using namespace std;

int a[4000];
int b[4000];
int t[4000 * 2];

constexpr int mis = 64;
int mi[mis];

void build(int i, int l, int r) {
  if (l == r - 1) {
    t[i] = b[l];
    return;
  }
  build(2 * i + 1, l, (l + r) / 2);
  build(2 * i + 2, (l + r) / 2, r);
  t[i] = min(t[2 * i + 1], t[2 * i + 2]);
}

int get(int i, int l, int r, int L, int R) {
  if (L <= l && R >= r) {
    return t[i];
  }
  if (R <= l || L >= r) {
    return 1e9;
  }
  return min(get(2 * i + 1, l, (l + r) / 2, L, R), get(2 * i + 2, (l + r) / 2, r, L, R));
}

int main() {
  int q;
  cin >> q;
  while (q--) {
    int n, m, k;
    cin >> n >> m >> k;
    k = min(k, m - 1);
    m -= 1;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    for (int i = 0; i <= m; ++i) {
      b[i] = max(a[i], a[(n - m - 1 + i) % n]);
      // cout << b[i] << ' ';
    }
    // cout << '\n';
    build(0, 0, m + 1);
    int ans = 0;
    for (int i = 0; i <= k; ++i) {
      // cout << get(0, 0, m + 1, i, i + m + 1 - k) << ' ';
      ans = max(ans, get(0, 0, m + 1, i, i + m + 1 - k));
    }
    // cout << '\n';
    cout << ans << '\n';
  }
}