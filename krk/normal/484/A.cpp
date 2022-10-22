#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> ii;

const int Maxb = 62;

int n;
ll l, r;
ii best;

ii getBest(ll x)
{
	int fir = -1;
	int bits = 0;
	for (int i = Maxb - 1; i >= 0; i--)
		if (x & 1ll << i) { fir = i; bits++; }
	int i = 1;
	ll num = x;
	while (i <= fir && (num ^ (1ll << i - 1)) <= r) { num ^= 1ll << i - 1; i++; }
	return ii(bits + i - 1, num);
}

int main()
{
	scanf("%d", &n);
	while (n--) {
		scanf("%I64d %I64d", &l, &r);
		best = ii(-1, 0);
		if (l == 0) l = 1;
		while (l <= r) {
			ii got = getBest(l);
			if (got.first > best.first) best = got;
			l += l & -l;
		}
		printf("%I64d\n", best.second);
	}
	return 0;
}