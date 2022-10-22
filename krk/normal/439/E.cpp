#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 100004;

vector <int> divs[Maxn];
int fac[Maxn], inv[Maxn];
int q;
int n, f;
int val[Maxn];

int toPower(int a, int p)
{
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * a % mod;
		p >>= 1; a = ll(a) * a % mod;
	}
	return res;
}

int F(int n, int f) { return n < f? 0: ll(fac[n - 1]) * inv[n - f] % mod * inv[f - 1] % mod; }

int main()
{
	for (int i = 1; i < Maxn; i++)
		for (int j = i + i; j < Maxn; j += i)
			divs[j].push_back(i);
	fac[0] = inv[0] = 1;
	for (int i = 1; i < Maxn; i++) {
		fac[i] = ll(fac[i - 1]) * i % mod;
		inv[i] = toPower(fac[i], mod - 2);
	}
	scanf("%d", &q);
	while (q--) {
		scanf("%d %d", &n, &f);
		int my = F(n, f);
		for (int i = 0; i < divs[n].size(); i++) {
			int cur = divs[n][i]; val[cur] = F(cur, f);
			for (int j = 0; j < divs[cur].size(); j++) {
				val[cur] -= val[divs[cur][j]];
				if (val[cur] < 0) val[cur] += mod;
			}
			my -= val[cur];
			if (my < 0) my += mod;
		}
		printf("%d\n", my);
	}
	return 0;
}