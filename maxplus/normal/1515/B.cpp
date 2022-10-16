#include <iostream>

using namespace std;

int sqrt(int n) {
  int r = __builtin_sqrt(n);
  return r * r;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    cout << (sqrt(n) / 4 * 4 == n || sqrt(n * 2) / 4 * 2 == n? "YES\n": "NO\n");
  }
  return 0;
}