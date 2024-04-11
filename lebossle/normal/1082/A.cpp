#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int ta=0; ta<t; ++ta) {
    int n, x, y, d;
    cin >> n >> x >> y >> d;
    int ans = n+1;
    if ((x-y)%d == 0)
      ans = min(ans, abs(x-y)/d);
    if ((y-1)%d == 0)
      ans = min(ans, (y-1)/d + (x+d-2)/d);
    if ((n-y)%d == 0)
      ans = min(ans, (n-y)/d + (n-x+d-1)/d);
    if (ans == n+1)
      ans = -1;
    cout << ans << endl;
  }
}