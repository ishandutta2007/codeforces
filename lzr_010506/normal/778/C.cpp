#include <bits/stdc++.h>
#define MaxN 300010
using namespace std;
int n, N, cnt, next[MaxN << 1], to[MaxN << 1], head[MaxN << 1], s[MaxN << 1], c[MaxN << 1][26], d[MaxN], ans[MaxN], f[MaxN << 1];
char ch[10], w[MaxN << 1];

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

void insert(int u, int v)
{
    to[++ cnt] = v;
    next[cnt] = head[u];
    head[u] = cnt;
}

int merge(int a, int b)
{
	if(!a || !b) return a | b;
	int x = ++ N, i;
	for(i = 0, s[x] = 1; i < 26; i ++)
		s[x] += s[c[x][i] = merge(c[a][i], c[b][i])];
	return x;
}

void dfs(int x)
{
	int i, j;
	for(s[x] = 1, i = head[x]; i; i = next[i])
		if(to[i] != f[x])
		{
			d[to[i]] = d[x] + 1;
			f[to[i]] = x;
			c[x][w[i] - 'a'] = to[i];
			dfs(to[i]);
			s[x] += s[to[i]];
		}
	ans[d[x]] += s[x];
	for(i = j = 0; i < 26; i ++)
		j = merge(j, c[x][i]);
	N = n;
	ans[d[x]] -= max(s[j], 1);
}

int main()
{
	n = read();
	for(int i = 1; i < n; i ++)
	{
		int j = read();
		int k = read();
		scanf("%s", ch);
		insert(j, k);
		w[cnt] = ch[0];
		insert(k, j);
		w[cnt] = ch[0];
	}

	N = n;
	dfs(1);
	int i = 0, j = 0;
	for(i = j = 0; i < n; i ++)
		if(ans[i] > ans[j]) j = i;

	cout << n - ans[j] << endl << j + 1;
	return 0;
}