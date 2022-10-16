#include <iostream>

using namespace std;

int main() {
  int q;
  cin >> q;
  while (q--) {
    string s;
    cin >> s;
    int z0 = s.find('1'), z1 = s.rfind('1'), ans = 0;
    for (int i = z0; i < z1; ++i) {
      ans += s[i] == '0';
    }
    cout << ans << '\n';
  }
}