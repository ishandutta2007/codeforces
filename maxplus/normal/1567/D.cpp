#include <iostream>

using namespace std;

constexpr int N = 1e9, C = 100;

int main()
{
  cin.tie(0), ios::sync_with_stdio(0);
  int t, s, n;
  cin >> t;
  while (t--) {
    cin >> s >> n;
    int idx = 0;
    int a[C]{};
    for (int v = N; v; v /= 10) {
      while (s - v >= max(n - idx - 1, 0)) {
        a[idx++ % n] += v;
        s -= v;
      }
    }
    for (int i = 0; i < n; ++i) {
      cout << a[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}