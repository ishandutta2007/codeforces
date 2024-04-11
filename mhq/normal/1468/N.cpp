//#ifdef DEBUG
//#define _GLIBCXX_DEBUG
//#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int c1, c2, c3;
  cin >> c1 >> c2 >> c3;
  int a1, a2, a3, a4, a5;
  cin >> a1 >> a2 >> a3 >> a4 >> a5;
  c1 -= a1;
  c2 -= a2;
  c3 -= a3;
  if (min({c1, c2, c3}) < 0) {
    cout << "NO\n";
    return;
  }
  a4 = max(a4 - c1, 0);
  a5 = max(a5 - c2, 0);
  if (a4 + a5 <= c3) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t;
  cin >> t;
  for (; t >= 1; t--) {
    solve();
  }
  return 0;
}