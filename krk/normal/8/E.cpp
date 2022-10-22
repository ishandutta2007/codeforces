#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

int n;
ll k;
ll res, rres;
bool stop;

void Print(ll res)
{
	for (int i = n - 1; i >= 0; i--)
		printf("%d", bool(res & 1ll << i));
	printf("\n");
}

ll Rev(ll cand)
{
	ll res = 0ll;
	for (int i = 0; i < n; i++)
		if (cand & 1ll << i) res |= 1ll << n - 1 - i;
	return res;
}

void Gen(int cur, int mask, int rmask, int lft)
{
	if (cur < 0) {
		ll myres = res | mask, myrres = ll(rmask) << n - lft | rres;
		if (myrres & 1ll << n - 1) myrres ^= (1ll << n) - 1;
		if (myres != 0 && myres <= myrres) k--;
		if (k == 0) { Print(myres); stop = true; }
	} else {
		Gen(cur - 1, mask, rmask, lft);
		if (stop) return;
		Gen(cur - 1, mask ^ 1 << cur, rmask ^ 1 << lft - 1 - cur, lft);
	}
}

int main()
{
	scanf("%d %I64d", &n, &k);
	int h = n / 2;
	int i;
	for (i = 0; i < 1ll << h - 1; i++) {
		int moreeq = (1ll << h - 1) - i;
		ll tot = 2 * moreeq - (i == 0);
		if (n % 2) tot += 2 * moreeq - 1;
		if (tot < k) { k -= tot; }
		else break;
	}
	if (i >= 1ll << h - 1) printf("-1\n");
	else {
		ll lft = n - h;
		res |= ll(i) << lft; rres = Rev(res);
		Gen(lft - 1, 0, 0, lft);
	}
	return 0;
}