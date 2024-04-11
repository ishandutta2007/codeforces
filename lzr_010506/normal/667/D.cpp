#include <bits/stdc++.h>
using namespace std;
int n, m, cnt, head[3010];

struct Edge
{
	int next, to;
}e[5010];

struct Node
{
	int u, dis;
	bool operator < (const Node &t) const
	{
		return dis > t.dis;
	}
	Node(int u = 0, int dis = 0):u(u),dis(dis) {}
}fm[3010][3010],to[3010][3010];

int dis[3010][3010], Ans[5];
queue<int> Q;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

void insert(int u, int v)
{
	e[++ cnt].next = head[u];
	e[cnt].to = v;
	head[u] = cnt;
}

void bfs(int s)
{
	while(!Q.empty()) Q.pop();
	Q.push(s);
	dis[s][s] = 0;
	while(!Q.empty())
	{
		int now = Q.front();
		Q.pop();
		for(int i = head[now]; i; i = e[i].next)
		{
			int y = e[i].to;
			if(!dis[s][y] && y != s)
			{
				dis[s][y] = dis[s][now] + 1;
				Q.push(y);
			}
		}
	}
	for(int i = 1; i <= n; i ++)
		if(!dis[s][i]) dis[s][i] = -0x7f7f7f7f;
}

int main()
{
	n = read();
	m = read();
	for(int i = 1; i <= m; i ++)
	{
		int u, v;
		u = read();
		v = read();
		insert(u, v);
	}
	for(int i = 1; i <= n; i ++) bfs(i);

	int ans = 0;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= n; j ++)
			fm[i][j] = Node(j, dis[j][i]);
		sort(fm[i] + 1, fm[i] + n + 1);
		for(int j = 1; j <= n; j ++)
			to[i][j] = Node(j, dis[i][j]);
		sort(to[i] + 1, to[i] + n + 1);
	}
	for(int x = 1; x <= n; x ++)
		for(int y = 1; y <= n; y ++)
		{
			if(x == y) continue;
			int j1 = 1, j2 = 1;
			while(fm[x][j1].u == y) j1 ++;
			while(to[y][j2].u == x) j2 ++;
			if(fm[x][j1].u == to[y][j2].u)
			{
				int nxt1 = j1 + 1;
				int nxt2 = j2 + 1;
				while(fm[x][nxt1].u == y) nxt1 ++;
				while(to[y][nxt2].u == x) nxt2 ++;
				if(fm[x][j1].dis - fm[x][nxt1].dis < to[y][j2].dis - to[y][nxt2].dis) j1 = nxt1;
				else j2 = nxt2;
			}

			if((long long)fm[x][j1].dis + to[y][j2].dis + dis[x][y] > ans)
			{
				ans = fm[x][j1].dis + to[y][j2].dis + dis[x][y];
				Ans[1] = fm[x][j1].u;
				Ans[2] = x;
				Ans[3] = y;
				Ans[4] = to[y][j2].u;
			}
		}
	for(int i = 1; i <= 4; i ++) cout << Ans[i] << " ";
	return 0;
}