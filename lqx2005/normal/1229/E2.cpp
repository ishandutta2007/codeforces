#pragma GCC optimize("3", "inline", "Ofast")
#include<bits/stdc++.h>
   
using namespace std;
   
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define sz(a) int((a).size())
#define x first
#define y second
#define mp make_pair
typedef long long i64;
typedef unsigned long long u64;
typedef vector<u64> DP;
const int N = 7, P = 1e9 + 7, B = 64;
const int M = 64185 + 10;

int n, tot = 0, f;
int p[N][N], prod[1 << N];
int dp[N + 1][M];
int nxt[M][1 << N];
map<DP, int> vis;

int power(int a, int b, int c = 1) {
	for(; b; b >>= 1, a = 1ll * a * a % P)
		if(b & 1)
			c = 1ll * c * a % P;
	return c;
}

void bfs(DP s) {
	queue<DP> q;
	q.push(s), vis[s] = ++tot;
	for(; !q.empty(); ) {
		DP u = q.front();
		int id = vis[u];
		q.pop();
		for(int i = 0; i < 1 << n; i++) {
			DP v((f + B - 1) / B);
			for(int j = 0; j < 1 << n; j++) {
				if(!(u[j / B] >> (j % B) & 1)) continue;
				int sub = (((1 << n) - 1) ^ j) & i;
				for(; sub; sub ^= sub & -sub) {
					int p = j ^ (sub & -sub);
					v[p / B] |= (u64)1 << (p % B);
				}
			}
			if(!vis.count(v)) {
				vis[v] = ++tot;
				nxt[id][i] = tot;
				q.push(v);
			} else nxt[id][i] = vis[v];
		}
	}
	return;
}

int main() {
	scanf("%d", &n);
	f = 1 << n;
	vector<u64> s((f + B - 1) / B);
	s[0] = 1;
	bfs(s);
//	cout << tot << endl;
	int inv = power(100, P - 2);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d", &p[i][j]);
			p[i][j] = 1ll * p[i][j] * inv % P;
		}
	}
	dp[0][1] = 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < (1 << n); j++) {
			prod[j] = 1;
			for(int k = 0; k < n; k++) {
				if(j >> k & 1) prod[j] = 1ll * prod[j] * p[i][k] % P;
				else prod[j] = 1ll * prod[j] * (1 - p[i][k] + P) % P;
			}
		}
		for(int j = 1; j <= tot; j++) {
			for(int k = 0; k < 1 << n; k++) {
				(dp[i + 1][nxt[j][k]] += 1ll * dp[i][j] * prod[k] % P) %= P;
			}
		}
	}
	s[0] = 0;
	int ans = (1 - dp[n][vis[s]] + P) % P;
	printf("%d\n", ans);
    return 0;
}