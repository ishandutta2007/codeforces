#include <iostream>
#include <algorithm>

using namespace std;

int a[200000];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    for (int i = 0; i / 2 < n; ++i) {
      cin >> a[i];
    }
    nth_element(a, a + n - 1, a + 2 * n);
    nth_element(a + n, a + n, a + 2 * n);
    std::cout << a[n] - a[n - 1] << '\n';
  }
}