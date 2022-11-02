#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  int m, s;
  cin >> m >> s;
  if (m == 1 && s == 0) {
    cout << 0 << " " << 0 << endl;
    return 0;
  }
  int low = 1;
  int high = 9 * m;
  if (s < low || s > high) {
    cout << -1 << " " << -1 << endl;
    return 0;
  }
  int have = s;
  for (int i = 0; i < m; i++) {
    int suf = (m - i - 1) * 9;
    int add = max(i ? 0 : 1, have - suf);
    cout << add;
    have -= add;
  }
  cout << " ";
  have = s;
  for (int i = 0; i < m; i++) {
    int add = min(9, have);
    cout << add;
    have -= add;
  }
  cout << endl;
  return 0;
}