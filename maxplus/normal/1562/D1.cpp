#include <iostream>
#include <memory.h>

using namespace std;

constexpr int N = 3e5;

int a[N];

int main()
{
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n, q, l, r;
  cin >> t;
  while (t--) {
    memset(a, 0, sizeof a);
    cin >> n >> q;
    cin.ignore();
    for (int i = 1; i <= n; ++i) {
      a[i] = a[i - 1] + (2 * (cin.get() == '+') - 1) * (2 * (i & 1) - 1);
    }
    for (int i = 0; i < q; ++i) {
      cin >> l >> r, --l;
      if ((r - l) & 1) {
        cout << "1\n";
      } else if (a[r] == a[l]) {
        cout << "0\n";
      } else {
        cout << "2\n";
      }
    }
  }
  return 0;
}