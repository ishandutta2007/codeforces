#include <algorithm>
#include <iostream>

using namespace std;

constexpr int N = 1 << 16;

int x[N];

int main()
{
  int n = 22, t1, t2, on = 0, maybe = -1;
  cin >> n;
  for (int i = 2; i <= 3; ++i) {
    cout << "AND 1 " << i << '\n';
    cin >> t1;
    on |= t1;
    cout << "OR 1 " << i << '\n';
    cin >> t2;
    maybe &= t2;
    x[i - 1] = t1 ^ t2;
  }
  for (int i = 4; i <= n; ++i) {
    cout << "XOR 1 " << i << '\n';
    cin >> x[i - 1];
  }
  cout << "AND 2 3\n";
  cin >> t1;
  int x0 = on | (maybe & ~t1);
  for (int i = 0; i < n; ++i) {
    x[i] ^= x0;
  }
  cout << '!';
  for (int i = 0; i < n; ++i) {
    cout << ' ' << x[i];
  }
  cout << '\n';
  return 0;
}