#include <iostream>
#include <utility>

using namespace std;

int main() {
  int n; cin >> n;
  int a = n, b = 1, x = 1, y = 0;
  for (int i = 2; i * i <= a; ++i) if (a % i == 0) {
    do {
      a /= i, b *= i;
    } while (a % i == 0);
    break;
  }
  int a0 = a, b0 = b;
  if (a == 1 || a == n) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  int x1 = 0, y1 = 1;
  while (b) {
    int q = a / b;
    x = exchange(x1, x - q * x1);
    y = exchange(y1, y - q * y1);
    a = exchange(b, a - q * b);
  }
  x *= -1, y *= -1;
  if (x < 0) x += b0;
  if (y < 0) y += a0;
  cout << "2\n";
  cout << y << ' ' << a0 << '\n';
  cout << x << ' ' << b0 << '\n';
}