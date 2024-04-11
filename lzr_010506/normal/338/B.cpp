#include <bits/stdc++.h>
using namespace std;

vector<int> e[100010];
int dep[100010], v[100010], g[100010];
int ans,n,m,k;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

void dfs(int x, int fa)
{
	for(int i = 0; i < e[x].size(); i ++)
	{
		int to = e[x][i];
		if(to == fa) continue;
		dfs(to, x);
		if(dep[to] > 0 || v[to])
            dep[x] = max(dep[x], dep[to] + 1);
	}
}
 
void solve(int x,int fa,int dis)
{
    if(k >= max(dis, dep[x])) ans ++;
    int l = 0, r = 0, a = 0, b = 0;
    for(int i = 0; i < e[x].size(); i ++)
    {
        int to = e[x][i];   
        if(to == fa)continue;
        g[to] = max(dis, l > 0 ? l + 1 : a);
        l = max(l, dep[to]);
        a |= v[to];
    }

    for(int i = e[x].size() - 1; i >= 0; i --)
    {
        int to = e[x][i];
        if(to == fa) continue;
        g[to] = max(g[to], r > 0 ? r + 1 : b);
        r = max(r, dep[to]);
        b |= v[to];
    }

    for(int i = 0; i < e[x].size(); i ++)
    {
        int to = e[x][i];
        if(to == fa)continue;
        if(g[to] > 0 || v[x]) solve(to, x, g[to] + 1);
        else solve(to, x, 0);
    }
}


int main()
{
	n = read();
	m = read();
	k = read();
	for(int i = 1; i <= m; i ++)
		v[read()] = 1;

	for(int i = 1; i < n; i ++)
	{
		int x, y;
		x = read();
		y = read();
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1, 1);
	solve(1, 1, 0);
	cout << ans;

	return 0;
}