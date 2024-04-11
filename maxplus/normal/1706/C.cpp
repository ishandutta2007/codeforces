#include <iostream>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  for (int t = (cin >> t, t + 1); --t; ) {
    int n, pp, p, c; cin >> n >> pp;
    uint64_t ans[2]{};
    if (n >= 2) cin >> p;
    if (n <= 2) { cout << "0\n"; continue; }
    for (int i = 2; i < n; ++i) {
      cin >> c;
      int cc = max({pp + 1, c + 1, p}) - p;
      ans[1] = min(ans[i & 1] += cc, ans[~i & 1]);
      pp = p, p = c;
    }
    cout << min(ans[0], n & 1? -1ull: ans[1]) << '\n';
  }
}