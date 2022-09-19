#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;
int gcd(int x, int y)
{
	return y == 0 ? x : gcd(y, x % y);
}
int power(int x, int t)
{
	int ret = 1;
	while(t > 0) {
		if(t & 1) ret = 1ULL * ret * x % MOD;
		x = 1ULL * x * x % MOD;
		t >>= 1;
	}
	return ret;
}

int fac[1000005], ifac[1000005], phi[1000005];
int n, a[1000005], cnt[1000005];
void solve()
{
	scanf("%d", &n);
	rep1(i, n) scanf("%d", &a[i]);
	
	rep1(i, n) cnt[i] = 0;
	rep1(i, n) cnt[a[i]] ++;
	sort(cnt + 1, cnt + 1 + n);
	reverse(cnt + 1, cnt + 1 + n);
	if(cnt[1] == n) {
		printf("1\n"); return;
	}
	int g = 0;
	rep1(i, n) g = gcd(g, cnt[i]);
	
	//i don't know how to ensure q != 0
	int p = 0, q = 0;
	rep1(i, g) if(g % i == 0) {
		int cp = 0, cq = 1;
		for(int j = 1; j <= n && cnt[j]; j ++) cq = 1ULL * cq * ifac[cnt[j] / i] % MOD;
		for(int j = 1; j <= n && cnt[j]; j ++) cp = (cp + 1ULL * cq * (cnt[j] / i) % MOD * (cnt[j] / i - 1)) % MOD;
		cq = 1ULL * cq * fac[n / i] % MOD;
		if(cp) cp = 1ULL * cp * fac[n / i - 2] % MOD;
		p = (p + 1ULL * cp * phi[i]) % MOD;
		q = (q + 1ULL * cq * phi[i]) % MOD;
	}
	p = 1ULL * p * power(q, MOD - 2) % MOD;
	p = 1ULL * n * (1 - p + MOD) % MOD;
	printf("%d\n", p);
}

const int MAXN = 1000000;
int main()
{
	fac[0] = 1;
	rep1(i, MAXN) fac[i] = 1ULL * fac[i - 1] * i % MOD;
	rep1(i, MAXN) ifac[i] = i == 1 ? 1 : MOD - 1ULL * ifac[MOD % i] * (MOD / i) % MOD;
	ifac[0] = 1;
	rep1(i, MAXN) ifac[i] = 1ULL * ifac[i - 1] * ifac[i] % MOD;
	rep1(i, MAXN) phi[i] = i;
	rep1(i, MAXN) for(int j = i * 2; j <= MAXN; j += i) phi[j] -= phi[i];
	
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}