#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define orz int
#define yjz main
#define FOR(i, x, y) for(int (i) = (x); (i) <= (y); (i) ++)
using namespace std;
const int N = 1010;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int n, m, Now, q[N], Dis[N], a[N][N];
vi g[N];

orz yjz()
{
	n = read();
	m = read();
	FOR(i, 1, n) 
		FOR(j,1,n) 
			if(i != j) 
				a[i][j] = 1;
	for(int i = 0; i < m; i ++)
	{
		int u,v;
		u = read();
		v = read();
		a[u][v] = a[v][u] = 2;
	}
	Now = 3 - a[1][n];
	FOR(i, 1, n) 
		FOR(j, 1, n) 
			if(a[i][j] == Now) 
				g[i].pb(j);
	int y,x; 
	y = x = 0; 
	q[x ++] = 1;
	memset(Dis, -1, sizeof(Dis)); 
	Dis[1]=0;
	while(y != x)
	{
		int u = q[y ++];
		for(auto v:g[u]) 
			if(Dis[v] < 0) 
				Dis[v] = Dis[u] + 1, q[x ++] = v;
	}
	printf("%d\n",Dis[n]);
	return 0;
}