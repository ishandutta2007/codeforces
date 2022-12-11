#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main() {
  lli n;
  cin >> n;
  lli ans = 0;
  for (lli i=2; i<=n; ++i)
    for (lli j=2; i*j<=n; j++)
      ans += 4*j;
  cout << ans << endl;
}