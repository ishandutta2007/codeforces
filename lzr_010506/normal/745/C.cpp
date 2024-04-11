#include <bits/stdc++.h>
#define ll long long
using namespace std;

int g[1010], fa[1010], vis[1010], cnt[1010], ecnt[1010], d[1010], tot, etot;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int Find(int x)
{
	if(fa[x] == x) return x;
	return fa[x] = Find(fa[x]);
}
void Union(int x, int y)
{
	int a = Find(x);
	int b = Find(y);
	if(a != b) fa[a] = b;
}

int main()
{
	int n, m, k;
	n = read();
	m = read();
	k = read();
	for(int i = 0; i < k; i ++)
	{
		int x;
		x = read();
		g[x] = 1;
	}
	for(int i = 1; i <= n; i ++) fa[i] = i;
	for(int i = 0; i < m; i ++)
	{
		int x, y;
		x = read();
		y = read();
		d[x] ++;
		d[y] ++;
		Union(x, y);
	}
	for(int i = 1; i <= n; i ++)
	{
		int p = Find(i);
		cnt[p] ++;
		ecnt[p] += d[i];
		if(g[i]) vis[p] = 1;
	}
	ll ans = 0;
	priority_queue<int> q;
	for(int i = 1; i <= n; i ++)
	{
		if(Find(i) != i) continue;
		if(vis[i])
		{
			ans += cnt[i] * (cnt[i] - 1) / 2 - ecnt[i] / 2;
			q.push(cnt[i]);
		}
		else tot += cnt[i], etot += ecnt[i];
	}
	ans += tot * (tot - 1) / 2 - etot / 2;
	if(q.size()) ans += tot * q.top();
	cout << ans;
	return 0;
}