#include <iostream>

using namespace std;

constexpr int N = 100, S = 1e4 + 1;

double cnt[N + 1][S];
int a[N];

int main() {
  int n, x; cin >> n >> x;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cnt[0][0] = 1;
  for (int i = 0, cs = 0; i < n && (cs += a[i], 1); ++i)
  for (int j = i; j >= 0; --j)
  for (int s = a[i]; s <= cs; ++s) {
    cnt[j + 1][s] += cnt[j][s - a[i]];
  }
  double ans = 0;
  for (int i = 1; i <= n; ++i) {
    double cs = 0;
    for (int s = 0; s < S; ++s) {
      cs += cnt[i][s] * min(x * (n + i), s * 2) / (i * 2);
    }
    for (int j = i + 1; j <= n; ++j) {
      cs /= j;
    }
    for (int j = n - i; j > 1; --j) {
      cs *= j;
    }
    ans += cs;
  }
  cout.precision(20);
  cout << fixed << ans;
}