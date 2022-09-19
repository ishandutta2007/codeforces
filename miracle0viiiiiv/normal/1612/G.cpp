#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 1e9 + 7;

int m, c, fac[1000005];
LL mem[2000015],* dif = mem + 1000005;

int main()
{
	fac[0] = 1;
	rep1(i, 1000000) fac[i] = 1ULL * fac[i - 1] * i % MOD;
	
	scanf("%d", &m);
	rep(i, m) {
		scanf("%d", &c); c --;
		dif[-c] ++; dif[c + 2] --;
	}
	for(int i = -999998; i <= 1000000; i ++) dif[i] += dif[i - 2];
	int a0 = 0, b0 = 0, a1 = 1;
	for(int i = 1000000; i >= -1000000; i --) {
		a0 = (a0 + 1ULL * b0 * dif[i] + 1ULL * dif[i] * (dif[i] - 1) / 2 % MOD * (MOD + i)) % MOD;
		b0 = (b0 + 1ULL * (MOD + i) * dif[i]) % MOD;
		a1 = 1ULL * a1 * fac[dif[i]] % MOD;
	}
	printf("%d %d\n", a0, a1);
	return 0;
}