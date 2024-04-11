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
    int a[56];
    int n; cin >> n;
    F1 (i, n) cin >> a[i];
    int l = -1, r = -1;
    F1 (i, n)
    {
      if (a[i]) r = i;
      if (a[n - i + 1]) l = n - i + 1;
    }
    int ans = 0;
    for (int i = l; i <= r; ++i)
      if (!a[i]) ++ans;
    cout << ans << '\n';
  }
}