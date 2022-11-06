#include <cstdio>
#include <queue>

using namespace std;

typedef pair<long long, int> P;
priority_queue<P, vector<P>, greater<P> > pq;
long long d[201000];
int h[201000], nxt[401000], to[401000], K = 0; long long cost[401000];

void ins(int u, int v, long long c) {nxt[++K] = h[u]; h[u] = K; to[K] = v; cost[K] = c;}

void dij()
{
	while(!pq.empty())
	{
		P p = pq.top(); pq.pop(); int u = p.second;
		if(d[u] < p.first) continue;
		for(int i = h[u]; i; i = nxt[i])
		{
			if(d[to[i]] > d[u] + cost[i])
			{
				d[to[i]] = d[u] + cost[i];
				pq.push(P(d[to[i]], to[i])); 
			}
		}
	}
}
int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		int u, v; long long c; scanf("%d%d%lld", &u, &v, &c);
		ins(u, v, c * 2); ins(v, u, c * 2);
	}
	for(int i = 1; i <= n; i++) 
	{
		long long a; scanf("%lld", &a);
		pq.push(P(d[i] = a, i)); 
	}
	dij();
	for(int i = 1; i <= n; i++)	printf("%lld ", d[i]);
	return 0;
}