#define NDEBUG
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  { int n; cin >> n; }
  string digits;
  cin >> digits;
  int c8 = 0, cother = 0;
  for (char ch : digits) {
    ++(ch == '8' ? c8 : cother);
  }
  int ans = 0;
  while (c8 > 0) {
    --c8;
    int need = 10;
    { int v = min(need, cother); need -= v; cother -= v; }
    { int v = min(need, c8);     need -= v; c8 -= v; }
    if (need > 0) {
      break;
    } else {
      ++ans;
    }
  }
  cout << ans << '\n';
}