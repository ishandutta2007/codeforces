#include <bits/stdc++.h>

using namespace std;

void solve() {
  int a, b, c; cin >> a >> b >> c;

  for (int x = 0; x * a <= c; x++) {
    if ((c - x * a) % b == 0) {
      cout << "Yes\n";
      return;
    }
  }

  cout << "No\n";
}

int main() {
  int cases; cases = 1;

  for (int i = 0; i < cases; i++) {
    solve();
  }

  return 0;
}