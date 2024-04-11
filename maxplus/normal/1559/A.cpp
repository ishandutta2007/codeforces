#include <iostream>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n, a;
  cin >> t;
  while (t--) {
    cin >> n;
    int nd = -1;
    while (n--) {
      cin >> a;
      nd &= a;
    }
    cout << nd << '\n';
  }
  return 0;
}