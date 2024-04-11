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
constexpr int N(3010), P(998244353), B = 1 << 12;
int n, c, a[N], p2[N], cnt[N], ans[N], to[N][N], inv[N];
int pd[N][B], dp[N][N];
int power(int a, int b, int c = 1) {
	for(; b; b >>= 1, a = 1ll * a * a % P) 
		if(b & 1)
			c = 1ll * c * a % P;
	return c;
}

void Add(int &x, int  y) { if((x += y) >= P && (x -= P)); }

void subtask1() {
	p2[0] = 1;
	for(int i = 1; i <= n; i++) {
		p2[i] = (p2[i - 1] << 1) % P;
		inv[i] = power(p2[i] - 1, P - 2);
	}
	for(int i = 0; i < n; i++) {
		for(int j = 1; j <= c; j++) cnt[j] = 0;
		int prod = 1, able = 0;
		for(int j = i + 1; j <= n; j++) {
			cnt[a[j]]++;
			if(cnt[a[j]] == 1) able++;
			if(cnt[a[j]] > 1) {
				prod = 1ll * prod * inv[cnt[a[j]] - 1] % P;
				prod = 1ll * prod * (p2[cnt[a[j]]] - 1) % P;
			}
			if(able < c) continue;
			to[i][j] = 1ll * prod * inv[cnt[a[j]]] % P;
		}
	}
	dp[0][0] = 1;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j <= n; j++) {
			for(int k = 0; k < n / c; k++) {
				Add(dp[j][k + 1], 1ll * dp[i][k] * to[i][j] % P);
			}
		}
	}
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= n / c; j++) {
			Add(ans[j], 1ll * dp[i][j] * p2[n - i] % P);
		}
	}
	for(int i = 0; i <= n; i++) ans[i] = (ans[i] - ans[i + 1] + P) % P;
	Add(ans[0], P - 1);
	for(int i = 0; i <= n; i++) cout << ans[i] <<" ";
	cout << endl;
	return;
}

void subtask2() {
	pd[0][0] = 1;
	for(int i = 0; i < n; i++) {
		for(int j = n / c; j >= 0; j--) {
			for(int msk = (1 << c) - 1; msk >= 0; msk--) {
				Add(pd[j][msk | (1 << (a[i + 1] - 1))], pd[j][msk]);
			}
			Add(pd[j + 1][0], pd[j][(1 << c) - 1]);
			pd[j][(1 << c) - 1] = 0;
		}
	}
	for(int i = 0; i <= n; i++) {
		int sum = 0;
		for(int j = 0; j < (1 << c); j++) Add(sum, pd[i][j]);
		if(i == 0) Add(sum, P - 1);
		cout << sum <<" ";
	}
	cout << endl;
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> c;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(c > 12) subtask1();
	else subtask2();
	return 0;
}