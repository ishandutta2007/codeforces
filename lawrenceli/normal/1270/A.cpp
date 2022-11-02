#include <bits/stdc++.h>

using namespace std;

int main() {
  int t; cin >> t;
  for (int i = 0; i < t; i++) {
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    int win = -1;
    for (int j = 0; j < k1; j++) {
      int a; cin >> a;
      if (a == n) win = 1;
    }
    for (int j = 0; j < k2; j++) {
      int a; cin >> a;
      if (a == n) win = 2;
    }
    assert(win != -1);
    cout << (win == 1 ? "YES\n" : "NO\n");
  }
}