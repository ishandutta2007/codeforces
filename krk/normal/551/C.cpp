#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll Inf = 1000000000000000ll;
const int Maxn = 100005;

int n, m;
int a[Maxn];
ll b[Maxn];
int cur;
ll res;

bool Ok(ll t)
{
	for (int i = 1; i <= n; i++)
		b[i] = a[i];
	cur = n;
	for (int i = 0; i < m; i++) {
		while (cur > 0 && b[cur] == 0) cur--;
		if (cur == 0) return true;
		ll hast = t;
		if (hast < cur) return false;
		hast -= cur;
		while (cur > 0 && hast) {
			ll tk = min(hast, b[cur]); 
			hast -= tk; b[cur] -= tk;
			if (b[cur] == 0) cur--;
		}
	}
	while (cur > 0 && b[cur] == 0) cur--;
	return cur < 1;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	ll l = 0, r = Inf;
	while (l <= r) {
		ll m = l + r >> 1;
		if (Ok(m)) { res = m; r = m - 1; }
		else l = m + 1;
	}
	printf("%I64d\n", res);
	return 0;
}