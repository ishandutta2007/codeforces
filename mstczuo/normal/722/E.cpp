# include <cstdio>
# include <algorithm>
# include <utility>
using namespace std;

const int maxn = 200010;
const int mod = 1000000007;

int fac[maxn], inv[maxn];

int power(int a,int b) {
	int t = 1;
	while(b) {
		if(b & 1) t = 1ll * t * a % mod;
		a = 1ll * a * a % mod;
		b = b >> 1;
	}
	return t;
}

void pre() {
	fac[0] = 1;
	for(int i = 1; i < maxn; ++i) fac[i] = 1ll * fac[i - 1] * i % mod;
	inv[maxn - 1] = power(fac[maxn - 1], mod - 2);
	for(int i = maxn - 1; i > 0; --i) inv[i - 1] = 1ll * inv[i] * i % mod;
}

int C(int n,int m) {
	return 1ll * fac[n + m] * inv[n] % mod * inv[m] % mod;
}


pair<int,int> a[2100];
int f[2100][36];
int n, m, k, s;

int main() {
	pre();
	scanf("%d%d%d%d", &n, &m, &k, &s);
	for(int i = 1; i <= k; ++i) 
		scanf("%d%d", &a[i].first, &a[i].second);
	sort(a + 1, a + k + 1);
	a[++k] = pair<int,int>(n, m);
	for(int i = 1; i <= k; ++i) {
		int way = C(a[i].first - 1, a[i].second - 1);
		for(int r = 1; r <= 32; ++r) f[i][r] = way;
		for(int j = 1; j < i; ++j) if(a[i].first >= a[j].first && a[i].second >= a[j].second) {
			long long way = C(a[i].first - a[j].first, a[i].second - a[j].second);
			for(int r = 1; r < 32; ++r) f[i][r] = (f[i][r] - f[j][r] * way) % mod;
		}
		for(int r = 32; r >= 1; --r) f[i][r] = (f[i][r] - f[i][r - 1]) % mod;
	}

	int ans = 0;
	for(int r = 1; r <= 32; ++r) {
		ans = (ans + 1ll * f[k][r] * s) % mod;
		s = (s + 1) / 2;
	}
	ans = 1ll * ans * power(C(n - 1, m - 1), mod - 2) % mod;
	if(ans < 0) ans += mod;
	printf("%d\n", ans);
	return 0;
}