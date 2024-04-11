#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxd = 18;
const int Maxm = 100;
const int Maxt = 10;

ll n;
int m;
int has[Maxd], d;
ll ways[1 << Maxd][Maxm];
int cnt[Maxt];
int pw[Maxd];
ll fac[Maxd + 1];

int main()
{
	scanf("%I64d %d", &n, &m);
	while (n) {
		has[d++] = n % 10; cnt[n % 10]++;
		n /= 10;
	}
	pw[0] = 1 % m;
	for (int i = 1; i < d; i++)
		pw[i] = 10 * pw[i - 1] % m;
	fac[0] = 1;
	for (int i = 1; i <= d; i++)
		fac[i] = fac[i - 1] * i;
	ways[0][0] = 1;
	for (int i = 0; i < 1 << d; i++) {
		int b = 0;
		for (int j = 0; j < d; j++)
			if (i & 1 << j) b++;
		for (int j = 0; j < m; j++) if (ways[i][j]) {
			for (int k = 0; k < d; k++)
				if (!(i & 1 << k) && (k < d - 1 || has[b]))
					ways[i | 1 << k][(j + has[b] * pw[k]) % m] += ways[i][j];
		}
	}
	ll res = ways[(1 << d) - 1][0];
	for (int i = 0; i < Maxt; i++)
		res /= fac[cnt[i]];
	printf("%I64d\n", res);
	return 0;
}