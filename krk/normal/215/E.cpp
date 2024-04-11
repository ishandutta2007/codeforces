#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxb = 61;

int koef[Maxb];
ll l, r;

ll Get(ll lim)
{
	if (lim == 0ll) return 0ll;
	ll res = 0ll;
	for (int p = 1; p < Maxb; p++)
		for (int r = 2; p * r < Maxb; r++) {
			ll dv = 0ll;
			for (int i = 0; i < r; i++) dv |= 1ll << (i * p);
			ll rig = min(lim / dv, (1ll << p) - 1ll);
			ll lef = 1ll << p - 1;
			if (lef <= rig) res += (rig - lef + 1) * koef[r];
		}
	return res;
}

int main()
{
	fill(koef + 2, koef + Maxb, 1);
	for (int i = 2; i < Maxb; i++)
		for (int j = 2 * i; j < Maxb; j += i)
			koef[j] -= koef[i];
	scanf("%I64d %I64d", &l, &r);
	printf("%I64d\n", Get(r) - Get(l - 1));
	return 0;
}