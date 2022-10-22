#include <cstdio>
using namespace std;

typedef long long ll;

int n, x, y, c;
int res;

ll Get(ll rad) { return rad * (rad + 1ll) / 2ll; }

ll getRes1(int x, int y, ll rad)
{
	if (!rad) return 0ll;
	ll all = Get(rad);
	if (rad - x > 0ll) all -= Get(rad - x);
	if (rad - (n + 1 - y) > 0ll) all -= Get(rad - (n + 1 - y));
	if (rad - x - (n + 1 - y) > 0ll) all += Get(rad - x - (n + 1 - y));
	return all;
}

ll getRes2(int x, int y, ll rad)
{
	if (!rad) return 0ll;
	ll all = Get(rad);
	if (rad - (n + 1 - x) > 0ll) all -= Get(rad - (n + 1 - x));
	if (rad - (n + 1 - y) > 0ll) all -= Get(rad - (n + 1 - y));
	if (rad - (n + 1 - x) - (n + 1 - y) > 0ll) all += Get(rad - (n + 1 - x) - (n + 1 - y));
	return all;
}

ll getRes3(int x, int y, ll rad)
{
	if (!rad) return 0ll;
	ll all = Get(rad);
	if (rad - (n + 1 - x) > 0ll) all -= Get(rad - (n + 1 - x));
	if (rad - y > 0ll) all -= Get(rad - y);
	if (rad - (n + 1 - x) - y > 0ll) all += Get(rad - (n + 1 - x) - y);
	return all;
}

ll getRes4(int x, int y, ll rad)
{
	if (!rad) return 0ll;
	ll all = Get(rad);
	if (rad - x > 0ll) all -= Get(rad - x);
	if (rad - y > 0ll) all -= Get(rad - y);
	if (rad - x - y > 0ll) all += Get(rad - x - y);
	return all;
}

bool Enough(int rad)
{
	ll res = getRes1(x, y, rad) + getRes2(x + 1, y, rad - 1) + getRes3(x + 1, y - 1, rad - 2) + getRes4(x, y - 1, rad - 1);
	return res >= c;
}

int main()
{
	scanf("%d %d %d %d", &n, &x, &y, &c);
	int l = 0, r = 2 * n;
	while (l <= r) {
		int mid = l + r >> 1;
		if (Enough(mid + 1)) { res = mid; r = mid - 1; }
		else l = mid + 1;
	}
	printf("%d\n", res);
	return 0;
}