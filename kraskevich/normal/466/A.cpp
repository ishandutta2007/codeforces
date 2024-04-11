#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  int res = (int)1e9;
  for (int i = 0; i <= n; i++) {
    int c = i / m + (i % m ? 1 : 0);
    res = min(res, c * b + (n - i) * a);
  }
  cout << res;
  return 0;
}