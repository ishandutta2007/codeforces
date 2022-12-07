#include <bits/stdc++.h>
#define FOR(i, x, y) for(int (i) = (x); (i) <= (y); (i) ++)
using namespace std;
const int N = 2000 + 10;
const int M = 100000 + 10;
struct Node
{
	int x, y;
}op[N*2];
int n, m, w, s, t, cnt, now, A[N], B[N], Map[N][N], vis[N], f[N][N], Bef[N];
void dfs(int u)
{
	if(vis[u])return; 
	vis[u] = 1;
	op[++ cnt] = (Node){A[u],B[u]};
	Bef[cnt] = now; 
	s += A[u]; 
	t += B[u];
	for(int v = 1; v <= n; v ++)
		if(Map[u][v]) dfs(v);
}
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
	w = read();
	FOR(i, 1, n) A[i] = read();
	FOR(i, 1, n) B[i] = read();
	FOR(i, 1, m)
	{
		int a,b; 
		a = read();
		b = read();
		Map[a][b] = Map[b][a] = 1;
	}
	FOR(i, 1, n) 
		if(!vis[i])
		{
			now = cnt; 
			s = 0; 
			t = 0; dfs(i);
			op[++ cnt] = (Node){s,t}; 
			Bef[cnt] = now;
		}
	FOR(i, 1, cnt) 
		FOR(j, 0, w) 
		{
			f[i][j] = f[i - 1][j];
			if(op[i].x <= j) f[i][j] = max(f[i][j], f[Bef[i]][j - op[i].x] + op[i].y);
		}
	int ans = 0;
	FOR(i, 0, w) ans = max(ans, f[cnt][i]);
	printf("%d\n",ans);
	return 0;
}