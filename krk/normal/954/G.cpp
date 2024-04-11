#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 500005;
const ll Inf = 2000000000000000000ll;

int n, r;
ll k;
int a[Maxn];
ll has[Maxn];
ll tmp[Maxn];

bool Get(ll lvl)
{
	fill(tmp, tmp + Maxn, 0ll);
	ll cur = 0;
	ll lft = k;
	for (int i = 1; i <= n; i++) {
		cur += tmp[i];
		ll my = cur + has[i];
		if (my < lvl) {
			ll nd = lvl - my;
			if (nd > lft) return false;
			lft -= nd;
			int ind = min(n, i + r);
			tmp[i + 1] += nd;
			tmp[min(n + 1, ind + r + 1)] -= nd;
		}
	}
	return true;
}

int main()
{
	scanf("%d %d", &n, &r);
	scanf("%I64d", &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		has[max(1, i - r)] += a[i];
		has[min(n + 1, i + r + 1)] -= a[i];
	}
	ll cur = 0;
	for (int i = 1; i <= n; i++) {
		cur += has[i]; has[i] = cur;
	}
	ll lef = 0, rig = Inf;
	while (lef <= rig) {
		ll mid = lef + rig >> 1ll;
		if (Get(mid)) lef = mid + 1;
		else rig = mid - 1;
	}
	cout << lef - 1 << endl;
	return 0;
}