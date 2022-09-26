#include <bits/stdc++.h>

using namespace std;

const int N = 300300;

int n, m;
long long x[N];
long long p[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  long long g = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
    if (i > 1) g = __gcd(g, x[i] - x[i - 1]);
  }
  for (int i = 1; i <= m; ++i) {
    cin >> p[i];
    if (g % p[i] == 0) {
      cout << "YES\n"<< x[1] << ' ' << i << '\n';
      return 0;
    }
  }
  cout << "NO\n";
}