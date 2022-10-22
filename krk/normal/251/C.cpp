#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxp = 360360;

ll a, b;
int k;
ll take[Maxp + 1], mem[Maxp];
ll res;

ll Get(ll a, ll b)
{
	ll dif = a - b;
	ll res = dif / ll(Maxp) * ll(take[Maxp]);
	return res + mem[dif % ll(Maxp)];
}

int main()
{
	scanf("%I64d %I64d %d", &a, &b, &k);
	mem[0] = 0;
	for (int i = 1; i < Maxp; i++) {
		ll nb = b + i;
		mem[i] = mem[i - 1] + 1;
		for (int j = 2; j <= k; j++)
			if (nb % ll(j) <= i) mem[i] = min(mem[i], mem[i - nb % ll(j)] + 1);
	}
	take[0] = 0;
	for (int i = 1; i <= Maxp; i++) {
		take[i] = take[i - 1] + 1;
		for (int j = 2; j <= k; j++)
			take[i] = min(take[i], take[i - i % j] + 1);
	}
	if (a - b < Maxp) printf("%I64d\n", mem[a - b]);
	else {
		res = Get(a, b);
		ll cand = 0ll;
		ll na = a;
		while (a - na < Maxp) {
			ll mx = 1;
			for (int j = 2; j <= k; j++)
				mx = max(mx, na % ll(j));
			na -= mx; cand++;
			if (na % ll(Maxp) == 0ll)
				res = min(res, cand + Get(na, b));
		}
		printf("%I64d\n", res);
	}
	return 0;
}