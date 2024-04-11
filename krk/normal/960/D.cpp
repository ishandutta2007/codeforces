#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxb = 62;

int q;
ll delt[Maxb];

ll getNum(int row, ll el)
{
	return (1ll << ll(row)) + el;
}

ll getRow(ll num)
{
	ll p = 0;
	while (1ll << p <= num) p++;
	return p - 1;
}

ll getReal(int row, ll el)
{
	el = (el - delt[row] + (1ll << ll(row))) % (1ll << ll(row));
	return getNum(row, el);
}

int main()
{
	scanf("%d", &q);
	while (q--) {
		int T;
		ll X, K; scanf("%d %I64d", &T, &X);
		if (T != 3) {
			scanf("%I64d", &K);
			int r = getRow(X);
			K %= (1ll << ll(r));
			if (K < 0) K += (1ll << ll(r));
			if (T == 1) delt[r] = (delt[r] + K) % (1ll << ll(r));
			else for (int i = r; i < Maxb; i++) {
					delt[i] = (delt[i] + K) % (1ll << ll(i));
					K *= 2ll;
				}
		} else {
			int r = getRow(X);
			ll el = X - (1ll << ll(r));
			el = (el + delt[r]) % (1ll << ll(r));
			while (r >= 0) {
				printf("%I64d%c", getReal(r, el), r - 1 >= 0? ' ': '\n');
				el /= 2; r--;
			}
		}
	}
	return 0;
}