#include <iostream>
#include <string>

using namespace std;

struct { int operator ()() { return *this; } template <typename T> operator T() { T t; cin >> t; return t; } } $;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  for (int testcase = $; testcase; --testcase) {
    int n = $, ans = 0;
    string s = string(n, '(') + string(n, ')');
    for (int i = 0; i < n; ++i) {
      cout << s << '\n';
      swap(s[2 * i + 1], s[i + n]);
    }
  }
  return 0;
}