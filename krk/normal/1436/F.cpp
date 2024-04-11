#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int Maxn = 100005;

int m;
int sqsum[Maxn], sum[Maxn];
ll cnt[Maxn];
int res[Maxn];

int toPower(int a, int p)
{
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * a % mod;
		p >>= 1; a = ll(a) * a % mod;
	}
	return res;
}

int main()
{
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a, f; scanf("%d %d", &a, &f);
		sqsum[a] = (sqsum[a] + ll(a) * a % mod * f) % mod;
		sum[a] = (sum[a] + ll(a) * f) % mod;
		cnt[a] += f;
	}
	for (int i = Maxn - 1; i > 0; i--) {
		int Sqsum = 0, Sum = 0;
		ll Cnt = 0;
		for (int j = i; j < Maxn; j += i) {
			Sqsum = (Sqsum + sqsum[j]) % mod;
			Sum = (Sum + sum[j]) % mod;
			Cnt += cnt[j];
		}
		int pw = (Cnt - 3ll + ll(mod - 1)) % (mod - 1);
		int coefa = Cnt <= 1? 0: Cnt % ll(mod) * toPower(2, pw) % mod;
		int coefb = Cnt <= 2? 0: (Cnt - 2) % ll(mod) * toPower(2, pw) % mod;
		res[i] = (ll(coefa) * Sum % mod * Sum % mod + ll(coefb) * Sqsum) % mod;
		for (int j = i + i; j < Maxn; j += i)
			res[i] = (res[i] - res[j] + mod) % mod;
	}
	printf("%d\n", res[1]);
    return 0;
}