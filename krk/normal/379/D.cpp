#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxk = 51;
const int Maxn = 105;

int k, x, n, m;
ll f[Maxk][3];
ll s[Maxk][2];
char a[Maxn], b[Maxn];

void Solve()
{
	for (int a1 = 0; a1 < 2; a1++)
		for (int b1 = 0; b1 < 2; b1++) if (n > 1 || !(a1 && b1))
			for (int a2 = 0; a2 < 2; a2++)
				for (int b2 = 0; b2 < 2; b2++) if (m > 1 || !(a2 && b2)) {
					ll has = (b1 && a2? f[k][0]: 0ll) + (b2 && a1? f[k][1]: 0ll) + (b2 && a2? f[k][2]: 0ll);
					if (has > x) continue;
					int lim1 = (n - a1 - b1) / 2, lim2 = (m - a2 - b2) / 2;
					for (ll i = 0; i <= lim1; i++)
						for (ll j = 0; j <= lim2; j++)
							if (has + i * s[k][0] + j * s[k][1] == x) {
								if (n == 1)
									if (a1) a[0] = 'C';
									else if (b1) a[0] = 'A';
									else a[0] = 'B';
								else {
									for (int t = 0; t < n; t++)
										a[t] = 'B';
									if (a1) a[0] = 'C';
									if (b1) a[n - 1] = 'A';
									for (int pos = a1 + 1, t = 0; t < i; t++, pos += 2) {
										a[pos - 1] = 'A'; a[pos] = 'C';
									}
								}
								a[n] = '\0';
								if (m == 1)
									if (a2) b[0] = 'C';
									else if (b2) b[0] = 'A';
									else b[0] = 'B';
								else {
									for (int t = 0; t < m; t++)
										b[t] = 'B';
									if (a2) b[0] = 'C';
									if (b2) b[m - 1] = 'A';
									for (int pos = a2 + 1, t = 0; t < j; t++, pos += 2) {
										b[pos - 1] = 'A'; b[pos] = 'C';
									}
								}
								b[m] = '\0';
								printf("%s\n%s\n", a, b);
								return;
							}
				}
	printf("Happy new year!\n");
}

int main()
{
	scanf("%d %d %d %d", &k, &x, &n, &m);
	s[1][0] = 1; s[2][1] = 1;
	f[3][0]++;
	f[4][0]++; f[4][1]++;
	for (int i = 5; i < Maxk; i++) {
		for (int j = 0; j < 3; j++)
			f[i][j] = f[i - 2][j] + f[i - 1][j];
		if (i % 2) f[i][2]++;
		else f[i][1]++;
	}
	for (int i = 3; i < Maxk; i++)
		for (int j = 0; j < 2; j++)
			s[i][j] = s[i - 2][j] + s[i - 1][j];
	Solve();
	return 0;
}