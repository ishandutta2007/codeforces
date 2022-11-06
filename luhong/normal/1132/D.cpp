#include <cstdio>
#include <queue>
#define MN 201000

typedef long long ll;
typedef std::pair<ll, ll> P;


int n, k;
ll a[MN]; int b[MN];
ll c[MN];
 
int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
	ll l = 0, r = 2e12 + 1;
	while(l < r)
	{
		ll mid = l + r >> 1;
		std::priority_queue<P, std::vector<P>, std::greater<P> > pq;
		for(int i = 1; i <= n; i++) pq.push(P(a[i] / b[i], i)), c[i] = a[i];
		bool ok = 0;
		for(int i = 0; i < k; i++)
		{
			P p = pq.top(); pq.pop();
			if(p.first < i) {ok = 1; break;}
			if(p.first >= k - 1) break;
			c[p.second] += mid; 
			p.first = c[p.second] / b[p.second];
			pq.push(p);
		}
		if(ok) l = mid + 1;
		else r = mid;
	}
	if(r == (ll)2e12 + 1) puts("-1");
	else printf("%lld\n", r);
	return 0;
}