#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

lli func(lli i, lli n, lli m) {
  // 1<=x<=n, x % m == i
  if (i == 0)
    i = m;
  n -= i;
  if (n < 0)
    return 0;
  return n/m+1;
}

int main() {
  lli n, m;
  cin >> n >> m;
  lli ans = 0;
  for (lli i=0; i<m; ++i)
    for (lli j=0; j<m; ++j)
      if ((i*i + j*j)%m == 0) {
        ans += func(i, n, m)*func(j, n, m);
      }
  cout << ans << endl;
}