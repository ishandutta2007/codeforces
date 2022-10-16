#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

constexpr int N = 300, MN = N * N;

pair<int, int> a[MN];
map<int, int> cnt;
bool b[MN];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n, m;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    cnt.clear();
    for (int i = 0; i < n * m; ++i) {
      cin >> a[i].first;
      ++cnt[a[i].first];
      a[i].second = i;
      b[i] = 0;
    }
    sort(a, a + n * m);
    for (int i = 0; i < n * m; ++i) {
      int val = a[i].first, cur = min(m - i % m, cnt[val]);
      for (int j = 0; j < cur; ++j) {
        a[i + j] = make_pair(a[i + j].second, i + cur - j - 1);
      }
      cnt[val] -= cur;
      i += cur - 1;
    }
    sort(a, a + n * m);
    int ans = 0;
    for (int i = 0; i < n * m; ++i) {
      for (int c = a[i].second - a[i].second % m; c < a[i].second; ++c) {
        ans += b[c];
      }
      b[a[i].second] = 1;
    }
    cout << ans << '\n';
  }
  return 0;
}