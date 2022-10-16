#include <iostream>

using namespace std;

int a[100];

int main() {
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    int z = 0, s = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (a[i] == 0) {
        ++z;
        a[i] = 1;
      }
      s += a[i];
    }
    cout << z + (s == 0) << '\n';
  }
}