#include<bits/stdc++.h>
using namespace std;
#define F1(i,n) for(int i = 1; i <= n; ++i)
#define int long long
const int maxn = 345678;
int a[maxn];
main()
{
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while (t --> 0)
  {
    int n; cin >> n;
    int neq = 0, pos;
    F1 (i, n) cin >> a[i];
    int mx = 0;
    F1 (i, n) mx = max(mx, a[i]);
    F1 (i, n) if (a[i] != mx) ++neq;
    F1 (i, n) if (a[i] == mx)
    {
      int cnt = 0;
      if (i != 1 && a[i - 1] != mx) ++cnt;
      if (i != n && a[i + 1] != mx) ++cnt;
      if (cnt)
      {
        pos = i;
        break;
      }
    }
    if (neq) cout << pos << '\n';
    else cout << -1 << '\n';
  }
}