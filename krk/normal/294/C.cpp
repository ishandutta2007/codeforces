#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 1005;

int pow2[Maxn];
int fact[Maxn], inv[Maxn];
int n, m;
int seq[Maxn];
int res = 1;

int Inv(int a)
{
	int p = mod - 2;
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * ll(a) % ll(mod);
		p >>= 1; a = ll(a) * ll(a) % ll(mod);
	}
	return res;
}

int main()
{
	pow2[0] = 1;
	for (int i = 1; i < Maxn; i++) pow2[i] = 2 * pow2[i - 1] % mod;
	fact[0] = 1; inv[0] = 1;
	for (int i = 1; i < Maxn; i++) {
		fact[i] = ll(i) * ll(fact[i - 1]) % ll(mod);
		inv[i] = Inv(fact[i]);
	}
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) scanf("%d", &seq[i]);
	sort(seq, seq + m);
	int tot = 0;
	tot += seq[0] - 1; res = ll(res) * ll(inv[seq[0] - 1]) % ll(mod);
	for (int i = 1; i < m; i++) {
		int dif = seq[i] - seq[i - 1] - 1;
		if (dif) { tot += dif; res = ll(res) * ll(inv[dif]) % ll(mod); res = ll(res) * ll(pow2[dif - 1]) % ll(mod); }
	}
	tot += n - seq[m - 1]; res = ll(res) * ll(inv[n - seq[m - 1]]) % ll(mod);
	res = ll(res) * ll(fact[tot]) % ll(mod);
	printf("%d\n", res);
	return 0;
}