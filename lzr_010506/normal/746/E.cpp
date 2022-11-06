#include <bits/stdc++.h>
using namespace std;
map<int, bool> vis;
set<int> nd;
int n, m, a[200010], c[2];
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int main()
{
	n = read();
	m = read();
	for(int i = 1; i <= n; i ++)
		a[i] = read();

	for(int i = 1; i <= n; i ++)
		if(vis[a[i]]) nd.insert(i);
		else
		{
			vis[a[i]] = 1;
			if(c[a[i] & 1] >= n / 2) nd.insert(i);
			else c[a[i] & 1] ++;
		}
	int ans = nd.size();
	for(int i = 1; i <= m; i ++)
	{
		if(c[0] == c[1] && c[0] == n / 2) break;
		if(!vis.count(i))
			if(c[i & 1] < n / 2)
			{
				c[i & 1] ++;
				a[ *nd.begin() ] = i;
				nd.erase( *nd.begin() );
			}
	}
	if(c[0] == c[1] && c[0] == n / 2)
	{
		cout << ans << endl;
		for(int i = 1; i <= n; i ++)
			cout << a[i] << " ";
	}
	else cout << -1;

	return 0;
}