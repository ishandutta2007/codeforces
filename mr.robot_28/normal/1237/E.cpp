#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int x = 1;
  while (x <= n) {
    if (n == x || n == x + 1) {
      cout << 1 << '\n';
      return 0;
    }
    if (x % 2 == 0) {
      x = x + 1 + x;
    } else {
      x = (x + 1) + 1 + x;
    }
  }
  cout << 0 << '\n';
  return 0;
}