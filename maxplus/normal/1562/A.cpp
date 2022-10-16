#include <iostream>

using namespace std;

int main()
{
  int t, l, r;
  cin >> t;
  while (t--) {
    cin >> l >> r;
    if ((r + 1) / 2 >= l) {
      cout << (r + 1) / 2 - 1 << '\n';
    } else {
      cout << r - l << '\n';
    }
  }
  return 0;
}