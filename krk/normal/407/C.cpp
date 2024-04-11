#include <cstdio>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 100005;
const int Maxk = 102;

int sp[Maxk][Maxn];
int n, m;
int delt[Maxk][Maxn];

void Add(int k, int l, int r, int val)
{
	if (val < 0) val += mod;
	delt[k][l] = (delt[k][l] + val) % mod;
	delt[k][r + 1] = (delt[k][r + 1] - val + mod) % mod;
}

int main()
{
	for (int j = 1; j < Maxn; j++)
		sp[0][j] = 1;
	for (int i = 1; i < Maxk; i++) {
		int cur = 0;
		for (int j = 1; j < Maxn; j++) {
			cur = (cur + sp[i - 1][j]) % mod;
			sp[i][j] = cur;
		}
	}
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int val; scanf("%d", &val);
		Add(0, i, i, val);
	}
	for (int i = 0; i < m; i++) {
		int l, r, k; scanf("%d %d %d", &l, &r, &k);
		Add(k, l, r, 1);
		int cur = 1;
		for (int j = k - 1; j >= 0; j--)
			delt[j][r + 1] = (delt[j][r + 1] - sp[k - j][r - l + 1] + mod) % mod;
	}
	for (int i = Maxk - 1; i >= 0; i--)
		for (int j = 1; j <= n; j++) if (delt[i][j]) {
			if (i) delt[i - 1][j] = (delt[i - 1][j] + delt[i][j]) % mod;
			delt[i][j + 1] = (delt[i][j + 1] + delt[i][j]) % mod;
		}
	for (int j = 1; j <= n; j++)
		printf("%d%c", delt[0][j], j + 1 <= n? ' ': '\n');
	return 0;
}