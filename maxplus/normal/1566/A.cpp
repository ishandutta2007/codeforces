#include <iostream>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n, s;
    cin >> n >> s;
    cout << s / ((n + 2) / 2) << '\n';
  }
  return 0;
}