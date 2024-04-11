#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define pii pair<int, int>
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef double db;
const int N = 1e5 + 10, K = 20;
int mu[N], vis[N], p[N], phi[N], tot = 0;
i64 sum[N];
i64 dp[K][N], now;
vector<int> fac[N];
void sieve(int n) {
	mu[1] = vis[1] = phi[1] = 1;
	for(int i = 2; i <= n; i++) {
		if(!vis[i]) p[++tot] = i, mu[i] = -1, phi[i] = i - 1;
		for(int j = 1; j <= tot && i * p[j] <= n; j++) {
			vis[i * p[j]] = 1;
			if(i % p[j] == 0) {
				mu[i * p[j]] = 0;
				phi[i * p[j]] = phi[i] * p[j];
				break;
			} 
			mu[i * p[j]] = - mu[i];
			phi[i * p[j]] = phi[i] * (p[j] - 1);
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j * i <= n; j++) {
			sum[j * i] += 1ll * mu[i] * j * (j - 1) / 2;
			if((j + 1) * i <= n) sum[(j + 1) * i] -= 1ll * mu[i] * j * (j - 1) / 2;
		}
	}
	for(int i = 1; i <= n; i++) sum[i] += sum[i - 1];
	for(int i = 1; i <= n; i++) {
		for(int j = i * 2; j <= n; j += i) {
			fac[j].push_back(i);
		}
	}
	return;
}

void modR(int l, int r, int x) {
	for(int i = sz(fac[r]) - 1; i >= 0; i--) {
		if(fac[r][i] >= l) now += phi[r / fac[r][i]] * x;
		else break;
	}
}

void modL(int l, int r, int x) {
	now += sum[r / l] * x;
	return;
}


void divide(int l, int r, int L, int R, int p) {
	if(l > r) return;
	int mid = (l + r) / 2, pos = -1;
	i64 res = LLONG_MAX;
	for(int i = r; i > mid; i--) modR(L + 1, i, -1);
	for(int i = L + 1; i <= min(mid, R + 1); i++) {
		if(dp[p - 1][i - 1] + now < res) {
			res = dp[p - 1][i - 1] + now;
			pos = i - 1;
		}
		modL(i, mid, -1);
	}
	dp[p][mid] = res;
	assert(pos != -1);
	for(int i = min(mid, R + 1); i >= L + 1; i--) modL(i, mid, 1);
	for(int i = mid + 1; i <= r; i++) modR(L + 1, i, 1);
	for(int i = r; i >= mid; i--) modR(L + 1, i, -1);
	divide(l, mid - 1, L, pos, p);
	for(int i = mid; i <= r; i++) modR(L + 1, i, 1);
	for(int i = L; i < pos; i++) modL(i + 1, r, -1);
	divide(mid + 1, r, pos, R, p);
	for(int i = pos - 1; i >= L; i--) modL(i + 1, r, 1);
	return;
}
void init(int n) {
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	for(int i = 1; i <= n; i++) modR(1, i, 1);
	for(int i = 1; i < K; i++) {
		divide(i, n, i - 1, n, i);
		modL(i, n, -1);
	}
	return;
}

void solve() {
	int n, k;
	cin >> n >> k;
	if(k >= 20) {
		printf("%d\n", n);
		return;
	}
	printf("%lld\n", dp[k][n] + n);
	return;
}

int main() {
	sieve(N - 10);
	init(N - 10);
	int T;
	for(scanf("%d", &T); T--; ) {
		solve();
	}
	return 0;
}