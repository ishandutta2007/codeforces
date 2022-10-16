#include <iostream>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int64_t t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    n = max((n + 1) / 2, 3ll);
    cout << n * 5 << '\n';
  }
  return 0;
}