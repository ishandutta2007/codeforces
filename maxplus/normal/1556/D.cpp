#include <algorithm>
#include <iostream>

using namespace std;

constexpr int N = 1e4;

int x[N];

int main()
{
  int n = 22, k, t1, t2, on = 0, maybe = -1;
  cin >> n >> k;
  for (int i = 2; i <= n; ++i) {
    cout << "and 1 " << i << '\n';
    cin >> t1;
    on |= t1;
    cout << "or 1 " << i << '\n';
    cin >> t2;
    maybe &= t2;
    x[i - 1] = t1 ^ t2;
  }
  cout << "and 2 3\n";
  cin >> t1;
  int x0 = on | (maybe & ~t1);
  for (int i = 0; i < n; ++i) {
    x[i] ^= x0;
  }
  sort(x, x + n);
  cout << "finish " << x[k - 1] << '\n';
  return 0;
}