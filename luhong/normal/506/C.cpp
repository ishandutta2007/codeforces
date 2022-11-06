#include <cstdio>
#include <iostream>
#include <cmath>
#include <queue>
#define MN 101000

typedef long long ll;

struct xxx{
	ll h, a, d;
}b[MN];

int n, m, k; ll P;
ll h[MN], a[MN];

bool operator > (xxx a, xxx b) {return a.d > b.d;}

std::priority_queue<xxx, std::vector<xxx>, std::greater<xxx> > pq;

bool check(ll x)
{
	while(!pq.empty()) pq.pop();
	for(int i = 1; i <= n; i++)
	{
		if(h[i] + m * a[i] > x)
		{
			ll t = h[i] + m * a[i] - x;
			ll lst = t % P; if(lst == 0) lst = P;
			b[i].d = ceil(1.0 * (lst - h[i]) / a[i] - 1e-10);
			b[i].h = h[i]; b[i].a = a[i];
			pq.push(b[i]);
		}
	}
	for(int i = 0; i < m; i++)
	{
		for(int j = 1; j <= k; j++)
		{
			if(pq.empty()) return 1;
			xxx p = pq.top(); pq.pop();
			
			ll H = p.h + p.a * i;
			p.h -= std::min(H, P);
			if(p.h + m * p.a > x)
			{
				ll t = p.h + m * p.a - x;
				ll lst = t % P; if(lst == 0) lst = P;
				p.d = ceil(1.0 * (lst - p.h) / p.a - 1e-10);
				pq.push(p);
			}
		}
	}
	if(pq.empty()) return 1;
	return 0; 
}

int main()
{
	scanf("%d%d%d%lld", &n, &m, &k, &P);
	for(int i = 1; i <= n; i++) scanf("%lld%lld", &h[i], &a[i]);
	ll l = 0, r = 1e13;
	while(l < r)
	{
		ll mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%lld\n", r);
}