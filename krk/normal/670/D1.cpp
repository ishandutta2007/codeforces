#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n, k;
int a[Maxn];
int b[Maxn];

bool Ok(ll need)
{
	ll myk = k;
	for (int i = 1; i <= n && myk >= 0; i++) {
		ll needb = ll(a[i]) * need;
		if (needb > b[i]) myk -= (needb - b[i]);
	}
	return myk >= 0;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	ll l = 0, r = 2000000000ll;
	ll res = 0;
	while (l <= r) {
		ll mid = l + r >> 1ll;
		if (Ok(mid)) { res = mid; l = mid + 1; }
		else r = mid - 1;
	}
	printf("%I64d\n", res);
	return 0;
}