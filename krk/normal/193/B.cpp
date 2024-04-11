#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll Inf = 9000000000000000000ll;
const int Maxn = 32;

int n, u, r;
int a[Maxn], b[Maxn], k[Maxn], p[Maxn];
int tmp[Maxn];
ll res = -Inf;

void getBest(int lvl, bool xr)
{
	if ((u - lvl) % 2 == 0) {
		ll cand = 0ll;
		for (int i = 1; i <= n; i++)
			cand += ll(a[i]) * ll(k[i]);
		res = max(res, cand);
	}
	if (lvl < u) {
		if (!xr) {
			for (int i = 1; i <= n; i++)
				a[i] ^= b[i];
			getBest(lvl + 1, true);
			for (int i = 1; i <= n; i++)
				a[i] ^= b[i];
		}
		for (int i = 1; i <= n; i++)
			tmp[i] = a[p[i]] + r;
		for (int i = 1; i <= n; i++)
			a[i] = tmp[i];
		getBest(lvl + 1, false);
		for (int i = 1; i <= n; i++)
			tmp[p[i]] = a[i] - r;
		for (int i = 1; i <= n; i++)
			a[i] = tmp[i];
	}
}

int main()
{
	scanf("%d %d %d", &n, &u, &r);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &k[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	getBest(0, false);
	printf("%I64d\n", res);
	return 0;
}