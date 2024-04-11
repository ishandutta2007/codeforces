#include <iostream>

using namespace std;

int main() {
  int q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    if (a == b) {
      cout << "0\n";
    } else {
      cout << 1 + ((a < b) == (a % 2 == b % 2)) << '\n';
    }
  }
}