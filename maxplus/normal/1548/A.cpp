#include <iostream>

using namespace std;

constexpr int N = 2e5 + 1;

int frenemies[N];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m, c = 1, a, b;
  cin >> n >> m;
  while (m--) {
    cin >> a >> b;
    n -= !frenemies[min(a, b)];
    n += !(frenemies[min(a, b)] += c);
  }
  cin >> m;
  while (m--) {
    cin >> c;
    if (c == 3) {
      cout << n << '\n';
    } else {
      cin >> a >> b;
      c = 3 - 2 * c;
      n -= !frenemies[min(a, b)];
      n += !(frenemies[min(a, b)] += c);
    }
  }
  return 0;
}