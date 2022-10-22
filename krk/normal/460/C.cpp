#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n, m, w;
int h[Maxn];
ll delt[Maxn];

bool Check(ll x)
{
	ll has = 0;
	fill(delt, delt + n + 1, 0);
	ll cur = 0;
	for (int i = 0; i < n && has <= m; i++) {
		cur += delt[i];
		if (h[i] + cur < x) {
			ll add = x - h[i] - cur;
			has += add; cur += add; delt[min(n, i + w)] -= add;
		}
	}
	return has <= m;
}

int main()
{
	scanf("%d %d %d", &n, &m, &w);
	for (int i = 0; i < n; i++)
		scanf("%d", &h[i]);
	ll l = 0, r = 2000000000;
	ll res;
	while (l <= r) {
		ll m = l + r >> 1ll;
		if (Check(m)) { res = m; l = m + 1; }
		else r = m - 1;
	}
	printf("%I64d\n", res);
	return 0;
}