#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, x, a, b;
  cin >> n >> x >> a >> b;
  cout << min(abs(b-a)+x, n-1) << endl;
}

int main() {
  int t;
  cin >> t;
  for (int ta=1; ta<=t; ++ta) {
    solve();
  }
}