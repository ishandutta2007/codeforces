#include <iostream>
#include <algorithm>
const int mxN = 1e6 + 5;
int freq[mxN];
void eat() {
  int n, m;
  std::cin >> n >> m;
  std::pair<int, int> r[n + 1], s[m + 1];
  for (int i = 1; i <= n; i++) std::cin >> r[i].first >> r[i].second;
  for (int i = 1; i <= m; i++) std::cin >> s[i].first >> s[i].second;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (r[i].first <= s[j].first && r[i].second <= s[j].second) {
        int dx = s[j].first - r[i].first + 1, dy = s[j].second - r[i].second + 1;
        freq[dx] = std::max(freq[dx], dy);
      }
    }
  }
  for (int i = mxN - 2; i > 0; i--) freq[i] = std::max(freq[i], freq[i + 1]);
  int ans = 2e9;
  for (int i = 1; i < mxN; i++) ans = std::min(ans, freq[i] + i - 1);
  std::cout << ans << "\n";
}
int32_t main() {
  int t = 1;
  // std::cin >> t;
  while (t--) eat();
}