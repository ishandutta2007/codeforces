#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int mod = 1000000007;

int fac[Maxn], ifac[Maxn];
int T;
int n, m, k;
int a[Maxn];

int toPower(int a, int p)
{
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * a % mod;
		p >>= 1; a = ll(a) * a % mod;
	}
	return res;
}

int Inv(int a) { return toPower(a, mod - 2); }

ll C2(ll n)
{
	if (n < 0 || 2 > n) return 0;
	return ll(n) * (n - 1) / 2ll;
}

int main()
{
	fac[0] = ifac[0] = 1;
	for (int i = 1; i < Maxn; i++) {
		fac[i] = ll(i) * fac[i - 1] % mod;
		ifac[i] = Inv(fac[i]);
	}
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n); m = 3; k = 2;
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n);
		ll res = 0;
		for (int i = 0; i < n; i++) {
			int j = upper_bound(a, a + n, a[i] + k) - a;
			res += C2(j - i - 1);
		}
		printf("%I64d\n", res);
	}
    return 0;
}