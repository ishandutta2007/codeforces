#include<bits/stdc++.h>
   
using namespace std;
   
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define sz(a) int((a).size())
#define x first
#define y second
#define mp make_pair
typedef long long i64;
typedef unsigned long long u64;
const int N = 6, M = 20, P = 1e9 + 7;
int n, p[N][N], e[N][N];
int dp[1 << M];
int tot = 0;
vector<int> g[M], rg[M];

int power(int a, int b, int c = 1) {
	for(; b; b >>= 1, a = 1ll * a * a % P)
		if(b & 1)
			c = 1ll * c * a % P;
	return c;
}

void dfs(int x, int ed, int cnt, vector<int> s, vector<int> t) {
	if(ed - x < cnt) return;
	if(cnt < 0) return;
	if(x == ed) {
		g[tot] = s;
		rg[tot++] = t;
		return;
	}
	s.push_back(x);
	dfs(x + 1, ed, cnt - 1, s, t);
	s.pop_back();
	t.push_back(x);
	dfs(x + 1, ed, cnt, s, t);
	return;
}


int main() {
	scanf("%d", &n);
	int inv = power(100, P - 2);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d", &p[i][j]);
			p[i][j] = 1ll * p[i][j] * inv % P;
		}
	}
	int mid = n / 2;
	dfs(0, n, mid, vector<int> (), vector<int> ());
	for(int i = 0; i < 1 << (mid * n); i++) {
		memset(e, 0, sizeof(e));
		int prod = 1;
		int mask = i;
		for(int j = 0; j < mid; j++) {
			for(int k = 0; k < n; k++) {
				e[j][k] = mask & 1, mask >>= 1;
				if(e[j][k]) prod = 1ll * prod * p[j][k] % P;
				else prod = 1ll * prod * (1 + P - p[j][k]) % P;
			}
		}
		mask = 0;
		for(int j = 0; j < tot; j++) {
			vector<int> p = g[j];
			int f = 0;
			do {
				int b = 1;
				for(int k = 0; k < mid; k++) {
					b &= e[k][p[k]];
				}
				f |= b;
			} 
			while(next_permutation(p.begin(), p.end()));
			mask ^= f << j;
		}
		(dp[mask] += prod) %= P; 
	}
	for(int i = 2; i <= 1 << tot; i <<= 1) {
		for(int j = 0; j < 1 << tot; j += i) {
			for(int k = 0; k < (i >> 1); k++) {
				(dp[j + k + (i >> 1)] += dp[j + k]) %= P;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < 1 << ((n - mid) * n); i++) {
		memset(e, 0, sizeof(e));
		int prod = 1;
		int mask = i;
		for(int j = mid; j < n; j++) {
			for(int k = 0; k < n; k++) {
				e[j][k] = mask & 1, mask >>= 1;
				if(e[j][k]) prod = 1ll * prod * p[j][k] % P;
				else prod = 1ll * prod * (1 + P - p[j][k]) % P;
			}
		}
		mask = 0;
		for(int j = 0; j < tot; j++) {
			vector<int> p = rg[j];
			int f = 0;
			do {
				int b = 1;
				for(int k = mid; k < n; k++) {
					b &= e[k][p[k - mid]];
				}
				f |= b;
			} 
			while(next_permutation(p.begin(), p.end()));
			f ^= 1;
			mask ^= f << j;
		}
		(ans += 1ll * prod * (1 - dp[mask] + P) % P) %= P;
	}
	printf("%d\n", ans);
    return 0;
}