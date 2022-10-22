#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 10;
const int mod = 1000000007;

int C[Maxn][Maxn];
int m;
int dig[Maxn];
int res;

int F(int n, int k)
{
	if (k > n) return 0;
	int res = C[n][k];
	for (int i = 0; i < n; i++)
		if (i < k) res *= 2;
		else res *= 8;
	return res;
}

void Calc(int lvl, int lim, int has)
{
	if (lvl == 0)
		res = (res + has) % mod;
	else for (int i = 0; i < Maxn && i < lim; i++) if (dig[i]) {
			dig[i]--;
			Calc(lvl - 1, lim - i, ll(has) * ll(dig[i] + 1) % ll(mod));
			dig[i]++;
		}
}

int main()
{
	for (int i = 0; i < Maxn; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
	}
	scanf("%d", &m);
	int tmp = m;
	int pw = 1, p = 0;
	while (pw <= tmp / 10) { pw *= 10; p++; }
	int lucky = 0;
	while (p >= 0) {
		int i;
		for (i = 1; i < Maxn && i * pw <= tmp; i++) {
			lucky += i - 1 == 4 || i - 1 == 7;
			for (int j = lucky; j < Maxn; j++)
				dig[j] += F(p, j - lucky);
			lucky -= i - 1 == 4 || i - 1 == 7;
		}
		lucky += i - 1 == 4 || i - 1 == 7;
		tmp %= pw; pw /= 10; p--;
	}
	dig[lucky]++;
	dig[0]--; // -0
	for (int i = 1; i < Maxn; i++) if (dig[i]) {
		dig[i]--;
		Calc(6, i, dig[i] + 1);
		dig[i]++;
	}
	printf("%d\n", res);
	return 0;
}