#include <iostream>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    int ans = -1;
    cin.ignore();
    char c = cin.get();
    for (int i = 1; i < n; ++i) {
      if (cin.peek() != c) {
        ans = i;
      }
      c = cin.get();
    }
    if (ans == -1) {
      cout << "-1 -1\n";
    } else {
      cout << ans << ' ' << ans + 1 << '\n';
    }
  }
  return 0;
}