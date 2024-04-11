#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1000010;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int n, m, Same, Dif;
int du[N], vis[N], f[N];

int find(int x)
{
    if(f[x] == x) return f[x];
    return f[x] = find(f[x]);
}

int main()
{
	n = read();
	m = read();
	for(int i = 1; i <= n; i ++) f[i] = i;
	for(int i = 1; i <= m; i ++)
	{
		int u, v;
		u = read();
		v = read();
		if(u == v) Same ++;
		else du[u] ++, du[v] ++, Dif ++;
		vis[u] = vis[v] = 1;
		int a = find(u);
		int b = find(v);
		if(a != b) f[a] = b;
	}
	int tmp = 0;
	for(int i = 1; i <= n; i ++)
		if(vis[i] && f[i] == i) tmp ++;
	if(tmp > 1)
	{
		puts("0");
		return 0;
	}
	ll ans = 0;
	for(int i = 1; i <= n; i ++)
		if(du[i] >= 2) ans += 1LL * du[i] * (du[i] - 1) / 2;
	ans += 1LL * Same * Dif;
	ans += 1LL * Same * (Same - 1) / 2;
	cout << ans;
	return 0;
}