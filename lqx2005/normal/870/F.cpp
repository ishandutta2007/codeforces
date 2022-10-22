#include<bits/stdc++.h>

using namespace std;

#define broken cerr << "running on " << __FUNCTION__ <<" "<< __LINE__ << endl
#define debug(x) cerr << #x <<" " << x << endl
#define x first
#define y second
#define mp make_pair
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
const int N = 1e7 + 10, M = 100 + 10, OO = 0x3f3f3f3f;
int n;
int f[M][M];
int mu[N], p[N], vis[N], fac[N], sum[N], tot = 0;
void subtask1() {
	memset(f, 0x3f, sizeof(f));
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(__gcd(i, j) > 1) {
				f[i][j] = 1;
			}
		}
	}
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			if(f[i][j] >= OO) f[i][j] = 0;
			ans += f[i][j];
		}
	}
	cout << ans << endl;
	return;
}

void sieve(int n) {
	vis[0] = vis[1] = fac[1] = mu[1] = 1;
	for(int i = 2; i <= n; i++) {
		if(!vis[i]) p[++tot] = i, mu[i] = -1, fac[i] = i;
		for(int j = 1; j <= tot && i * p[j] <= n; j++) {
			vis[i * p[j]] = 1;
			fac[i * p[j]] = p[j];
			if(i % p[j] == 0) {
				mu[i * p[j]] = 0;
				break;
			}
			mu[i * p[j]] = - mu[i];
		}
	}
	for(int i = 2; i <= n; i++) if(vis[i]) sum[fac[i]]++;
	for(int i = 1; i <= n; i++) sum[i] += sum[i - 1];
	return;
}

void subtask2() {
	sieve(n);
	int cnt = n - 1;
	for(int i = 1; i <= tot; i++) if(p[i] * 2 > n) cnt--;
	i64 all = 1ll * cnt * (cnt - 1) / 2;
	i64 c1 = 0;
	for(int i = 1; i <= n; i++) c1 += 1ll * mu[i] * (n / i) * (n / i);
	c1 = 1ll * n * n - c1;
	c1 -= n - 1;
	c1 = c1 / 2;
	all -= c1;
	i64 c2 = 0;
	for(int i = 1; i <= tot; i++) {
		c2 += sum[n / p[i]] - (n / p[i]) + 1;
	}
	int pos = tot;
	for(int i = 1; i <= tot; i++) {
		while(pos > 0 && p[pos] * p[i] > n) pos--;
		if(pos > i) c2 += pos - i;
	}
	i64 np = n - 1 - tot, pr = np * (np - 1) / 2;
	pr -= c1;
	for(int i = 1; i <= tot; i++) pr += n / p[i] - 1;
	c2 += pr;
	i64 c3 = all - c2;
	cout << c1 + c2 * 2 + c3 * 3 << endl;
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	subtask2();
	return 0;
}