#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int tot = 1;
int t[N * 30][2], sum[N * 30];

void ins(int k, int v)
{
	int cur = 1;
	sum[cur] += v;
	for (int d = 30; d >= 0; d --)
	{
		int c = (k >> d) & 1;
		if (!t[cur][c]) t[cur][c] = ++ tot;
		cur = t[cur][c];
		sum[cur] += v;
	}
}

int k, l;
int ans = 0;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

void dfs(int u, int eq, int d)
{
	if (!eq)
	{
		ans += sum[u];
		return;
	}
	if (d < 0)
	{
		ans += sum[u];
		return;
	}
	int c = (k >> d) & 1, cl = (l >> d) & 1;
	if (t[u][0])
	{
		if (c ^ 0)
		{
			if (eq && !cl);
			else dfs(t[u][0], eq, d - 1);
		}
		else
		{
			if (eq && !cl) dfs(t[u][0], 1, d - 1);
			else dfs(t[u][0], 0, d - 1);
		}
	}
	if (t[u][1])
	{
		if (c ^ 1)
		{
			if (eq && !cl);
			else dfs(t[u][1], eq, d - 1);
		}
		else
		{
			if (eq && !cl) dfs(t[u][1], 1, d - 1);
			else dfs(t[u][1], 0, d - 1);
		}
	}
}

int main()
{
	int q, op;
	q = read();
	while (q --)
	{
		op = read();
		k = read();
		if (op == 1) ins(k, 1);
		if (op == 2) ins(k, -1);
		if (op == 3)
		{
			cin >> l;
			l --;
			ans = 0;
			dfs(1, 1, 30);
			cout << ans << endl;
		}
	}
	return 0;
}