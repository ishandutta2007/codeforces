#include <iostream>

using namespace std;

int a[100002][2];

int main() {
  int n, q;
  cin >> n >> q;
  int bad = 0;
  while (q--) {
    int r, c;
    cin >> r >> c;
    --r;
    bad -= a[c][r] && a[c][r ^ 1];
    bad -= a[c][r] && a[c + 1][r ^ 1];
    bad -= a[c][r] && a[c - 1][r ^ 1];
    a[c][r] ^= 1;
    bad += a[c][r] && a[c][r ^ 1];
    bad += a[c][r] && a[c + 1][r ^ 1];
    bad += a[c][r] && a[c - 1][r ^ 1];
    if (bad) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
    }
  }
}