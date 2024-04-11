#include <bits/stdc++.h>
using namespace std;

void solve() {
  int x, y;
  cin >> x >> y;
  if (x > 3 || x == y) {
    cout << "YES" << endl;
    return;
  }
  if (x == 1 || y > 3) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
}

int main() {
  int t;
  cin >> t;
  for (int ta=1; ta<=t; ++ta) {
    solve();
  }
}