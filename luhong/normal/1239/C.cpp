#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm> 
#define MN 101000

int n, p, q[MN], h = 0, t = 0;
struct xxx{
	int x, id;
}d[MN];
long long Ans[MN];

std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
 
bool cmp(xxx a, xxx b) {return a.x == b.x ? a.id < b.id : a.x < b.x;}

int main()
{
	scanf("%d%d", &n, &p);
	for(int i = 1; i <= n; i++) scanf("%d", &d[i].x), d[i].id = i;
	long long now = 0;
	std::sort(d + 1, d + n + 1, cmp);
	int i = 1; h = 0, t = -1;
	while(i <= n)
	{
		now = d[i].x;
		while(i <= n && d[i].x <= now) pq.push(d[i++].id);
		if(!pq.empty() && (h > t || pq.top() < q[t])) q[++t] = pq.top(), pq.pop();
		
		while(h <= t)
		{
			now += p; int u = q[h];
			Ans[u] = now;
			while(i <= n && d[i].x < now)
			{
				pq.push(d[i++].id);
				if(h > t || pq.top() < q[t]) q[++t] = pq.top(), pq.pop();
			}
			h++;
			while(i <= n && d[i].x <= now) pq.push(d[i++].id);
			if(!pq.empty() && (h > t || pq.top() < q[t])) q[++t] = pq.top(), pq.pop();
		}
	}
	for(int i = 1; i <= n; i++) printf("%lld ", Ans[i]);
}