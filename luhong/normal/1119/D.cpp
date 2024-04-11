#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#define MN 101000

typedef long long ll;

ll a[MN], b[MN], Ans[MN];
struct xxx{ll x; int id;} q[MN];

bool cmp(xxx a, xxx b) {return a.x < b.x;}

int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	int Q; scanf("%d", &Q);
	for(int i = 1; i <= Q; i++)
	{
		ll l, r; scanf("%lld%lld", &l, &r);
		q[i].x = r - l; q[i].id = i;
	}
	std::sort(a + 1, a + n + 1);
	std::sort(q + 1, q + Q + 1, cmp);
	for(int i = 1; i < n; i++) b[i] = a[i + 1] - a[i];
	std::sort(b + 1, b + n);
	int tot = 0;
	ll sum = 0;
	int j = 1;
	for(int i = 1; i <= Q; i++)
	{
		while(j <= n - 1 && b[j] <= q[i].x)
		{
			tot++; sum += b[j];
			j++;
		}
		Ans[q[i].id] = sum + (n - tot) * (q[i].x + 1);
	}
	for(int i = 1; i <= Q; i++) printf("%lld ", Ans[i]);
}