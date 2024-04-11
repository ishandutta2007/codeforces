#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
ll l, r;

ll Solve1(ll x)
{
	ll res = 0;
	ll pw = 1;
	for (int i = 0; i <= 18; i++, pw *= 10ll) if (pw <= x) {
		ll dig = x / pw;
		for (int j = 1; j < dig && j <= 9; j++)
			res++;
		if (dig < 10) res++;
	}
	return res;
}

ll Solve2(ll x)
{
	ll res = 0;
	ll pw = 1;
	for (int i = 0; i <= 18; i++, pw *= 10ll) if (pw <= x) {
		ll dig = x / pw;
		for (int j = 1; j < dig && j <= 9; j++)
			res += 1 + ll(i) * 9;
		if (dig < 10)
			res += 1 + Solve1(x % pw);
	}
	return res;
}

ll Solve3(ll x)
{
	ll res = 0;
	ll pw = 1;
	for (int i = 0; i <= 18; i++, pw *= 10ll) if (pw <= x) {
		ll dig = x / pw;
		for (int j = 1; j < dig && j <= 9; j++)
			res += 1 + ll(i) * 9 + ll(i) * (i - 1) / 2ll * 9 * 9;
		if (dig < 10)
			res += 1 + Solve2(x % pw);
	}
	return res;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%I64d %I64d", &l, &r);
		printf("%I64d\n", Solve3(r) - Solve3(l - 1));
	}
    return 0;
}