#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 32;
const ll Inf = 4000000000000000000ll;

int n, q;
ll cnt[Maxn];
ll a[Maxn];

int Get(int ind, int n, ll &k, ll &res)
{
	int sav = n;
	for (int i = ind + 1; i < n; i++) {
		ll tk = min(a[i], k / (1 << (i - ind)));
		a[ind] += ll(tk) * (1 << (i - ind));
		a[i] -= tk;
		k -= ll(tk) * (1 << (i - ind));
		res += ll(tk) * ((1 << (i - ind)) - 1);
		if (a[i] > 0) { sav = i; break; }
	}
	return sav;
}

ll Finish(int ind, ll k)
{
	ll res = 0;
	ll cur = 0;
	for (int i = ind; i > 0; i--) {
		cur += a[i];
		ll tk = min(cur, k);
		cur = 2 * tk;
		k -= tk;
		res += tk;
	}
	return k <= 0? res: Inf;
}

ll Solve(int ind, ll k)
{
	for (int i = 0; i < n; i++)
		a[i] = cnt[i];
	ll sum = 0;
	for (int i = 0; i <= ind; i++)
		sum += a[i];
	if (sum >= k) return 0;
	ll gres = Inf;
	ll res = 0;
	k -= sum;
	while (true) {
		int nw = Get(ind, n, k, res);
		if (k <= 0) { gres = min(gres, res); return gres; }
		gres = min(gres, res + Finish(ind, k));
		if (nw >= n) return gres;
		a[nw]--;
		a[nw - 1] += 2;
		if (nw - 1 == ind) k -= 2;
		res++;
		if (k <= 0) { gres = min(gres, res); return gres; }
	}
	return -1;
}

int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &cnt[i]);
	while (q--) {
		int typ, ind;
		ll val; scanf("%d %d %I64d", &typ, &ind, &val);
		if (typ == 1) cnt[ind] = val;
		else {
			ll got = Solve(ind, val);
			printf("%I64d\n", got >= Inf? -1ll: got);
		}
	}
    return 0;
}