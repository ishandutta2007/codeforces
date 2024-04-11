#include <bits/stdc++.h>

using namespace std;

const string N = "no\n";
const string Y = "yes\n";

int main() {
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, k, d1, d2;
    cin >> n >> k >> d1 >> d2;
    if (n % 3) {
      cout << N;
      continue;
    }
    if ((2 * d1 + d2 + k) % 3 == 0) {
      long long x1 = (2 * d1 + d2 + k) / 3;
      long long x2 = x1 - d1;
      long long x3 = x2 - d2;
      if (x2 >= 0 && x3 >= 0 && x1 <= n / 3) {
        cout << Y;
        continue;
      }
    }
    swap(d1, d2);
    if ((2 * d1 + d2 + k) % 3 == 0) {
      long long x1 = (2 * d1 + d2 + k) / 3;
      long long x2 = x1 - d1;
      long long x3 = x2 - d2;
      if (x2 >= 0 && x3 >= 0 && x1 <= n / 3) {
        cout << Y;
        continue;
      }
    }
    if (d1 < d2)
      swap(d1, d2);
    d1 -= d2;
    if ((2 * d1 + d2 + k) % 3 == 0) {
      long long x1 = (2 * d1 + d2 + k) / 3;
      long long x2 = x1 - d1;
      long long x3 = x2 - d2;
      if (x2 >= 0 && x3 >= 0 && x1 <= n / 3) {
        cout << Y;
        continue;
      }
    }
    swap(d1, d2);
    if ((2 * d1 + d2 + k) % 3 == 0) {
      long long x1 = (2 * d1 + d2 + k) / 3;
      long long x2 = x1 - d1;
      long long x3 = x2 - d2;
      if (x2 >= 0 && x3 >= 0 && x1 <= n / 3) {
        cout << Y;
        continue;
      }
    }
    cout << N;
  }
  return 0;
}