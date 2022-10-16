#include <iostream>

using namespace std;

constexpr int N = 3e5;

int x[N];

int main()
{
  cin.tie(0), ios::sync_with_stdio(0);
  for (int i = 1; i < N; ++i) {
    x[i] = x[i - 1] ^ i;
  }
  int t, a, b;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    if (x[a - 1] == b) {
      cout << a << "\n";
    } else if (x[a - 1] ^ b ^ a) {
      cout << a + 1 << "\n";
    } else {
      cout << a + 2 << "\n";
    }
  }
  return 0;
}