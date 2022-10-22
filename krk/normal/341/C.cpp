#include <cstdio>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 2005;

int C[Maxn][Maxn];
int fact[Maxn];
int n;
bool tval[Maxn], tpos[Maxn];
int a, b;
int F[Maxn];

int main()
{
	for (int i = 0; i < Maxn; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	}
	fact[0] = 1;
	for (int i = 1; i < Maxn; i++)
		fact[i] = ll(fact[i - 1]) * ll(i) % ll(mod);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a; scanf("%d", &a);
		if (i == a) { printf("0\n"); return 0; }
		if (a != -1) { tval[a] = true; tpos[i] = true; }
	}
	for (int i = 1; i <= n; i++)
		if (!tval[i])
			if (!tpos[i]) a++;
			else b++;
	for (int i = a; i >= 0; i--) {
		F[i] = ll(C[a][i]) * ll(fact[a - i + b]) % ll(mod);
		for (int j = i + 1; j <= a; j++) {
			F[i] -= ll(C[j][i]) * ll(F[j]) % ll(mod);
			if (F[i] < 0) F[i] += mod;
		}
	}
	printf("%d\n", F[0]);
	return 0;
}