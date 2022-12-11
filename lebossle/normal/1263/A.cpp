#include <bits/stdc++.h>
using namespace std;

void solve() {
  int r, g, b;
  cin >> r >> g >> b;
  r = min(r, b+g);
  g = min(g, b+r);
  b = min(b, r+g);
  int ans = (r+g+b)/2;
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  for (int ta=0; ta<t; ++ta) {
    solve();
  }
}