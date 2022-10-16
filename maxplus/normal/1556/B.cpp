#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n, a;
  cin >> t;
  while (t--) {
    cin >> n;
    int ans[2]{}, rem[2]{};
    for (int i = 0; i < n; ++i) {
      cin >> a;
      ++rem[a & 1];
      ans[0] += std::abs((rem[0] - rem[1]) - (~i & 1)) / 2;
      ans[1] += std::abs((rem[0] - rem[1]) + (~i & 1)) / 2;
    }
    if (std::abs(rem[0] - rem[1]) > 1) {
      cout << "-1\n";
      continue;
    }
    cout << (n & 1? ans[rem[0] < rem[1]]: min(ans[0], ans[1])) << '\n';
  }
  return 0;
}