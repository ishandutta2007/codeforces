#include <iostream>

using namespace std;

template <typename T = int> T read() { T t; cin >> t; return t; }

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t = read();
  while (t--) {
    int n = read(), ans = 0;
    while (n--) {
      auto c = read<char>();
      ans += (c != '0' && n) + c - '0';
    }
    cout << ans << '\n';
  }
  return 0;
}