#include <algorithm>
#include <iostream>

using namespace std;

constexpr int N = 300, MN = N * N;

pair<int, int> a[MN];
bool b[MN];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n, m;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i < n * m; ++i) {
      cin >> a[i].first;
      a[i].second = -i;
      b[i] = 0;
    }
    sort(a, a + n * m);
    for (int i = 0; i < n * m; ++i) {
      a[i].first = -a[i].second;
      a[i].second = i;
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