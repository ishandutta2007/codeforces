#include <iostream>
#include <memory.h>

using namespace std;

constexpr int N = 3e5 + 1;

int a[N];

int sum(int l, int r) {
  return a[r] - a[l];
}

int solve(int L, int R) {
  int l = L, r = R, mid, sumr = (sum(L, R - 1) > 0) - (sum(L, R - 1) < 0), summ;
  while (r - l > 1) {
    mid = (r + l) / 2;
    summ = sum(L, mid) - sum(mid + 1, R);
    if (summ * sumr > 0) {
      r = mid;
    } else {
      l = mid;
    }
  }
  return l;
}

int main()
{
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n, q, l, r;
  cin >> t;
  while (t--) {
    cin >> n >> q;
    cin.ignore();
    for (int i = 1; i <= n; ++i) {
      a[i] = a[i - 1] + (2 * (cin.get() == '+') - 1) * (2 * (i & 1) - 1);
    }
    for (int i = 0; i < q; ++i) {
      cin >> l >> r, --l;
      if (a[r] == a[l]) {
        cout << "0\n";
        continue;
      } else if ((r - l) & 1) {
        cout << "1\n";
      } else {
        cout << "2\n" << r << ' ';
      }
      cout << solve(l, r - !((r - l) & 1)) + 1 << '\n';
    }
  }
  return 0;
}