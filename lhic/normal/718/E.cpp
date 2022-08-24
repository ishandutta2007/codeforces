#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

const int INF = 20;

int dd[20][20];
int dd2[20][20];
int c[120000];
char s[120000];
int n;
int go[120000][10];
int tp[120000];
int cc[10][270];
int cnt[10];
ll dp[30];

void upd(int a, int b, int c) {
	if (dd[a][b] > c)
		dd[a][b] = c, dd[b][a] = c;
}
void add(int x, ll y) {
	dp[x] += y;
}

int main() {
	scanf("%d", &n);
	scanf(" %s", s);
	for (int i = 0; i < n; ++i)
		c[i] = s[i] - 'a';
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j) {
			dd[i][j] = INF;
		}
	for (int i = 0; i < 8; ++i)
		dd[i][i] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j < 8 && i + j < n; ++j) {
			upd(c[i], c[i + j], j);
		}
	}
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j)
			dd2[i][j] = dd[i][j] + 1;
	for (int i = 0; i < 8; ++i)
		dd2[i][i] = 0;
	for (int k = 0; k < 8; ++k)
		for (int i = 0; i < 8; ++i)
			for (int j = 0; j < 8; ++j) {
				dd2[i][j] = min(dd2[i][j], dd2[i][k] + dd2[k][j]);
			}
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j)
			++dd2[i][j], dd2[i][j] = min(dd2[i][j], INF);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 8; ++j)
			go[i][j] = INF;
		for (int j = 0; j < 8 && i + j < n; ++j) {
			for (int k = 0; k < 8; ++k)
				go[i][k] = min(go[i][k], j + dd2[c[i + j]][k]);
		}
		for (int j = 0; j < 8 && i - j >= 0; ++j) {
			for (int k = 0; k < 8; ++k)
				go[i][k] = min(go[i][k], j + dd2[c[i - j]][k]);
		}
		for (int j = 0; j < 8; ++j)
			if (dd2[c[i]][j] != go[i][j])
				tp[i] ^= (1 << j);
		++cc[c[i]][tp[i]];
		++cnt[c[i]];
	}
	for (int i = 0; i < 8; ++i) {
		add(1, (ll)cnt[i] * (cnt[i] - 1) / 2);
	}
	for (int i = 0; i < 8; ++i)
		for (int j = i + 1; j < 8; ++j) {
			for (int k = 0; k < 256; ++k)
				for (int l = 0; l < 256; ++l) {
					int cur = INF;
					for (int x = 0; x < 8; ++x)
						cur = min(cur, dd2[i][x] + dd2[x][j] - ((k >> x) & 1) - ((l >> x) & 1) - 1);
					add(cur, ll(cc[i][k]) * cc[j][l]);
				}
		}
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j < 8 && i - j >= 0; ++j) {
			int cur = INF;
			for (int k = 0; k < 8; ++k)
				cur = min(cur, go[i][k] + go[i - j][k] - 1);
			if (cur > j) {
				add(cur, -1);
				add(j, 1);
			}
		}
	}
	for (int i = 20; i >= 0; --i) {
		if (dp[i]) {
			cout << i << " " << dp[i] << "\n";
			return 0;
		}
	}
	return 0;
}