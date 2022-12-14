#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, x, y, cnt, l[5555555], r[5555555], sub[5555555], cur, pw[555555], p, ans;
vector<int> v;
void add(int x)
{
	cur = 1;
	for (int i = 29; i >= 0; i--)
	{
		sub[cur]++;
		if (x & (1 << i))
		{
			if (!r[cur]) r[cur] = ++cnt;
			cur = r[cur];
		}
		else
		{
			if (!l[cur]) l[cur] = ++cnt;
			cur = l[cur];
		}
	}
	sub[cur]++;
}
void dfs(int i, int dep)
{
	if (dep == p)
	{
		v.push_back(i);
		return;
	}
	if (l[i]) dfs(l[i], dep - 1);
	if (r[i]) dfs(r[i], dep - 1);
}
int calc(int ll, int rr, int dep)
{
	if (!ll || !rr) return 0;
	if (dep < 0) return 1ll * (pw[sub[ll]] - 1) * (pw[sub[rr]] - 1) % mod;
	if (x & (1 << dep))
	{
		int xx = calc(l[ll], r[rr], dep - 1), yy = calc(r[ll], l[rr], dep - 1);
		return (1ll * (pw[sub[l[ll]]] - 1) * (pw[sub[l[rr]]] - 1) + 1ll * (pw[sub[r[ll]]] - 1) * (pw[sub[r[rr]]] - 1) + 1ll * xx * (pw[sub[r[ll]]] + pw[sub[l[rr]]] - 1) + 1ll * yy * (pw[sub[l[ll]]] + pw[sub[r[rr]]] - 1) + 1ll * xx * yy) % mod;
	}
	return (calc(l[ll], l[rr], dep - 1) + calc(r[ll], r[rr], dep - 1)) % mod;
}
int main()
{
	scanf("%d%d", &n, &x); cnt = 1;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &y);
		add(y);
	}
	pw[0] = 1;
	for (int i = 1; i <= n; i++) pw[i] = (pw[i - 1] + pw[i - 1]) % mod;
	p = -1;
	for (int i = 29; i >= 0; i--)
	{
		if (x & (1 << i)) 
		{
			p = i;
			break;
		}
	}
	dfs(1, 29); 
	if (p == -1)
	{
		for (int i = 0; i < v.size(); i++)
		{
			ans = (ans + pw[sub[v[i]]] - 1) % mod;
		}
	}
	else
	{
		for (int i = 0; i < v.size(); i++)
		{
			ans = (ans + pw[sub[l[v[i]]]] - 1) % mod;
			ans = (ans + pw[sub[r[v[i]]]] - 1) % mod;
			ans = (ans + calc(l[v[i]], r[v[i]], p - 1)) % mod;
		}
	}
	printf("%d\n", (ans + mod) % mod);
	return 0;
}