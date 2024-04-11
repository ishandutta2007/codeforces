#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const ll lim = 10000000000ll;

int n, m;
ll h[Maxn];
ll p[Maxn];
ll res;

bool Possible(ll pos, ll l, ll r, ll tim)
{
	if (pos <= l) return r - pos <= tim;
	if (r <= pos) return pos - l <= tim;
	return r - l + min(pos - l, r - pos) <= tim;
}

bool Enough(ll tim)
{
	int j = 0;
	for (int i = 0; i < n && j < m; i++) {
		int l = j;
		while (l < m && Possible(h[i], p[j], p[l], tim)) l++;
		j = l;
	}
	return j == m;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &h[i]);
	for (int i = 0; i < m; i++)
		scanf("%I64d", &p[i]);
	ll lef = 0ll, rig = 2ll * lim;
	while (lef <= rig) {
		ll mid = lef + rig >> 1ll;
		if (Enough(mid)) { res = mid; rig = mid - 1ll; }
		else lef = mid + 1ll;
	}
	printf("%I64d\n", res);
	return 0;
}