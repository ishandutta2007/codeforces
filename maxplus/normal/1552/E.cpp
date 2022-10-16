#include <iostream>
#include <memory.h>

using namespace std;

constexpr int N = 101;
int epoch[N];
int l[N];
int r[N];

int main()
{
  int n, k, c, op = N, ep = 0;
  cin >> n >> k;
  for (int i = 1; i <= n * k; ++i) {
    cin >> c;
    if ((n + k - 2) / (k - 1) <= op) {
      ++ep;
      op = 0;
    }
    if (r[c]) {
    } else if (epoch[c] == ep) {
      r[c] = i;
      ++op;
    } else {
      l[c] = i;
      epoch[c] = ep;
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << l[i] << ' ' << r[i] << '\n';
  }
  return 0;
}