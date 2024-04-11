#include<bits/stdc++.h>
using namespace std;
#define F(i,n) for (int i = 0; i < n; ++i)
#define F1(i,n) for (int i = 1; i <= n; ++i)
#define int long long
const int maxn = 5678;
int a[maxn];
//vector<int> v[maxn];
//map<int, vector<int> > app;
main()
{
  ios::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  int ans = 1;
  F1 (i, n / 2 - 1) ans *= i * (i + n / 2);
  cout << ans << '\n';
}