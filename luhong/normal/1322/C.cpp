#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define MN 501000 

typedef long long ll;

ll gcd(ll a, ll b) {return b == 0 ? a : gcd(b, a % b);}

struct xxx{
	std::vector<int> v;
	ll c;
}d[MN];

bool cmp(xxx a, xxx b) {return a.v == b.v ? a.c < b.c: a.v < b.v;}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int n, m; scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++) scanf("%lld", &d[i].c);
		for(int i = 1; i <= m; i++)
		{
			int x, y; scanf("%d%d", &x, &y);
			d[y].v.push_back(x);
		}
		for(int i = 1; i <= n; i++) std::sort(d[i].v.begin(), d[i].v.end());
		std::sort(d + 1, d + n + 1, cmp);
		ll ans = -1;
		int j;
		for(int i = 1; i <= n; i = j)
		{
			j = i; ll sum = 0;
			while(j <= n && d[j].v == d[i].v) sum += d[j++].c;
			if(d[i].v.size() == 0) continue;
			if(ans == -1) ans = sum;
			else ans = gcd(ans, sum);
		}
		printf("%lld\n", ans);
		for(int i = 1; i <= n; i++) d[i].v.clear();
	}
}