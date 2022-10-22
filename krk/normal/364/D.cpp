#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;

int n;
ll a[Maxn];
ll D[Maxn];
int has[Maxn];
int dlen;
ll res;

int Random(int n)
{
	return (rand() << 15 | rand()) % n;
}

ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	for (int cnt = 0; cnt < 13; cnt++) {
		ll val = a[Random(n)];
		dlen = 0;
		for (ll i = 1; i * i <= val; i++)
			if (val % i == 0) {
				D[dlen++] = i;
				if (val / i != i) D[dlen++] = val / i;
			}
		sort(D, D + dlen); fill(has, has + dlen, 0);
		for (int i = 0; i < n; i++) {
			ll g = gcd(val, a[i]);
			has[lower_bound(D, D + dlen, g) - D]++;
		}
		for (int i = 0; i < dlen; i++) if (D[i] > res) {
			for (int j = i + 1; j < dlen; j++)
				if (D[j] % D[i] == 0) has[i] += has[j];
			if (2 * has[i] >= n) res = D[i];
		}
	}
	printf("%I64d\n", res);
	return 0;
}