#include <iostream>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, a, b;
  int64_t cnt[2][2]{};
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    ++cnt[a / 2 % 2][b / 2 % 2];
  }
  int64_t ans = 0;
  for (int a: {0, 1})
  for (int b: {0, 1}) {
    ans += cnt[a][b] * (cnt[a][b] - 1) * (cnt[a][b] - 2) / 6;
  }
  for (int a: {0, 1})
  for (int b: {0, 1})
  for (int c: {0, 1})
  for (int d: {0, 1}) if (a != c || b != d) {
    ans += cnt[a][b] * (cnt[a][b] - 1) * cnt[c][d] / 2;
  }
  cout << ans << '\n';
  return 0;
}