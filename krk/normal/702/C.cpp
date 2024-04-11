#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
ll a[Maxn];
int m;
ll b[Maxn];

bool Ok(ll x)
{
	for (int i = 0; i < n; i++)
		if (upper_bound(b, b + m, a[i] + x) - lower_bound(b, b + m, a[i] - x) <= 0)
			return false;
	return true;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	for (int i = 0; i < m; i++)
		scanf("%I64d", &b[i]);
	sort(b, b + m);
	ll l = 0, r = 2000000000;
	ll res;
	while (l <= r) {
		ll mid = l + r >> 1ll;
		if (Ok(mid)) { res = mid; r = mid - 1; }
		else l = mid + 1;
	}
	printf("%I64d\n", res);
	return 0;
}