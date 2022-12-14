#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int n, m, a[1111], x, y, s, t, cnt, b[1111], pre[1111]; 
int dist[1111], h[1111];
int head[1111], to[44444], nxt[44444], cap[44444], cost[44444];
bool used[1111], flag;
void addedge(int x, int y, int cp, int cst)
{
	++cnt; to[cnt] = y; cap[cnt] = cp; cost[cnt] = cst;
	nxt[cnt] = head[x]; head[x] = cnt;
}
void spfa()
{
	queue<int> q;
	q.push(s); memset(used, 0, sizeof(used));
	for (int i = 1; i <= t; i++) dist[i] = -2e9;
	dist[s] = 0; used[s] = 1;
	while(!q.empty())
	{
		x = q.front(); q.pop(); used[x] = 0;
		for (int i = head[x]; i; i = nxt[i])
		{
			if (cap[i] && dist[to[i]] < dist[x] + cost[i])
			{
				dist[to[i]] = dist[x] + cost[i];
				pre[to[i]] = i;
				if (!used[to[i]])
				{
					used[to[i]] = 1;
					q.push(to[i]);
				}
			}
		}
	}
}
void dijk()
{
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, s));
	for (int i = 1; i <= t; i++) dist[i] = -2e9;
	dist[s] = 0;
	while(!pq.empty())
	{
		x = pq.top().second; y = pq.top().first;
		pq.pop();
		if (dist[x] != y) continue;
		for (int i = head[x]; i; i = nxt[i])
		{
			if (cap[i] && dist[to[i]] < dist[x] + cost[i] + h[x] - h[to[i]])
			{
				dist[to[i]] = dist[x] + cost[i] + h[x] - h[to[i]];
				pq.push(make_pair(dist[to[i]], to[i]));
				pre[to[i]] = i;
			}
		}
	}
}
void mcf()
{
	while(1)
	{
		if (!flag)
		{
			spfa();
			flag = 1;
		}
		else dijk();
		for (int i = 1; i <= t; i++) h[i] += dist[i];
		if (h[t] <= 0) break;
		x = t;
		while(x != s)
		{
			cap[pre[x]] --;
			cap[pre[x] ^ 1] ++;
			x = to[pre[x] ^ 1];
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	s = n + 1; t = n + 2; cnt = 1;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &x, &y);
		addedge(x, y, inf, a[x] - a[y]);
		addedge(y, x, 0, a[y] - a[x]);
	}
	for (int i = 1; i <= n; i++)
	{
		addedge(s, i, 1, 0);
		addedge(i, s, 0, 0);
		addedge(i, t, 1, 0);
		addedge(t, i, 0, 0);
	}
	mcf();
	for (int i = 1; i <= n; i++)
	{
		for (int j = head[s]; j; j = nxt[j])
		{
			if (to[j] == i) 
			{
				x = cap[j];
				break;
			}
		}
		for (int j = head[i]; j; j = nxt[j])
		{
			if (to[j] == t)
			{
				y = cap[j];
				break;
			}
		}
		if (!x && !y) 
		{
			x = y = 1;
		}
		for (int j = head[s]; j; j = nxt[j])
		{
			if (to[j] == i) 
			{
				cap[j] = x;
				cap[j ^ 1] = x ^ 1;
				break;
			}
		}
		for (int j = head[i]; j; j = nxt[j])
		{
			if (to[j] == t)
			{
				cap[j] = y;
				cap[j ^ 1] = y ^ 1; 
				break;
			}
		}
	}
	spfa();
	for (int i = 1; i <= n; i++) printf("%d ", a[i] + dist[i]);
	printf("\n");
	return 0;
}