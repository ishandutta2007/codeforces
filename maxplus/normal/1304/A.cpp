#include <iostream>

using namespace std;

int main() {
  int q;
  cin >> q;
  while (q--) {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    if ((y - x) % (a + b) == 0) {
      cout << (y - x) / (a + b) << '\n';
    } else {
      cout << -1 << '\n';
    }
  }
}