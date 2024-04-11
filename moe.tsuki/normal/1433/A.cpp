#include<bits/stdc++.h>
using namespace std;
#define F1(i,n) for(int i = 1; i <= n; ++i)
#define int long long
main()
{
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while (t --> 0)
  {
    int x; cin >> x;
    int ans = 0;
    F1 (i, 9)
    {
      int out = 0;
      int cur = 0;
      F1 (j, 4)
      {
        cur *= 10;
        cur += i;
        ans += j;
        if (cur == x) { out = 1; break; }
      }
      if (out) break;
    }
    cout << ans << '\n';
  }
}