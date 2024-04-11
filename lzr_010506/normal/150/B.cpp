#include <bits/stdc++.h>
#define ll long long
using namespace std;

int f[2010];

int find(int x)
{
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
}
int n, m, k;
int main()
{
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i ++) f[i] = i;
	int cnt = n;
	for(int i = 1; i <= n; i ++)
	{
		int l = i;
		int r = l + k - 1;
		if(r > n) break;
		while(l < r)
		{
			int x = find(l);
			int y = find(r);
			if(x != y) cnt --;
			f[x] = y;
			l ++;
			r --;
		}
	}
	ll ans = 1ll;
	for(int i = 1; i <= cnt; i ++)
		ans = ans * (ll)m % 1000000007;
	cout << ans;
	return 0;
}