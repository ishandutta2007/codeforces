#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll Inf = 20000000000ll;
const int Maxn = 100005;

int n;
int a[Maxn];
ll res;

bool Enough(ll x)
{
	ll has = 0ll;
	for (int i = 0; i < n && has < x; i++)
		has += x - ll(a[i]);
	return has >= x;
}

int main()
{
	scanf("%d", &n);
	ll lef = 0ll, rig = Inf;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		lef = max(lef, ll(a[i]));
	}
	while (lef <= rig) {
		ll mid = lef + rig >> 1ll;
		if (Enough(mid)) { res = mid; rig = mid - 1ll; }
		else lef = mid + 1ll;
	}
	printf("%I64d\n", res);
	return 0;
}