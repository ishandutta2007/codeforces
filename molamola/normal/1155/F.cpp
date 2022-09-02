#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_set>
#include <bitset>
#include <time.h>
#include <limits.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define Fi first
#define Se second
#define pb push_back
#define szz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;

const int _N = 14;
int n, m;
int path[_N][1<<_N][_N];
vector <int> cyc[_N][1<<_N][_N], cyc2[1<<_N];
char LC[_N][1<<_N][_N];
int E[_N][_N];
int dp[1<<_N];
t3 pdp[1<<_N];

void dfs(int b) {
	if(szz(cyc2[b])) {
		int m = szz(cyc2[b]);
		rep(i, m) printf("%d %d\n", cyc2[b][i] + 1, cyc2[b][(i+1)%m] + 1);
	}
	else {
		t3 p = pdp[b];
		int st, en, bi;
		tie(st, en, bi) = p;
		int tbi = b ^ bi ^ (1<<st|1<<en);
		if(st != en) {
			int m = szz(cyc[st][tbi][en]);
			for(int i=1;i<m;i++) printf("%d %d\n", cyc[st][tbi][en][i-1] + 1, cyc[st][tbi][en][i] + 1);
		}
		else {
			int m = szz(cyc2[tbi]);
			rep(i, m) printf("%d %d\n", cyc2[tbi][i] + 1, cyc2[tbi][(i+1)%m] + 1);
		}
		dfs(bi);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	rep(i, m) {
		int x, y; scanf("%d%d", &x, &y);
		--x; --y;
		E[x][y] = E[y][x] = 1;
	}
	for(int i=0;i<n;i++) {
		path[i][1<<i][i] = 1;
		cyc[i][1<<i][i].pb(i);
		rep(b, 1<<n) rep(j, n) if(path[i][b][j]) {
			rep(k, n) {
				if(E[j][k] && !(1<<k & b) && path[i][b|1<<k][k] == 0) {
					path[i][b|1<<k][k] = 1;
					cyc[i][b|1<<k][k] = cyc[i][b][j];
					cyc[i][b|1<<k][k].pb(k);
				}
			}
			
			if(E[j][i] && szz(cyc2[b]) == 0 && __builtin_popcount(b) > 2) {
				cyc2[b] = cyc[i][b][j];
			}
		}
	}
	rep(i, n) rep(j, 1<<n) rep(k, n) LC[i][j][k] = szz(cyc[i][j][k]);
	memset(dp, -1, sizeof dp);
	dp[0] = 0;
	rep(i, 1<<n) if(szz(cyc2[i])) dp[i] = szz(cyc2[i]);
	for(int i=1;i<1<<n;i++) {
		if(dp[i] == __builtin_popcount(i)) continue;
		for(int j=(i-1)&i;;j=(j-1)&i) {
			if(dp[j] != -1) {
				rep(a, n) if(1<<a & j) rep(b, a) if(1<<b & j) {
					int c = 1<<a | 1<<b;
					int t = LC[a][i^j^c][b];
					if(t == 0) continue;
					if(dp[i] == -1 || dp[i] > dp[j] + t - 1) {
						dp[i] = dp[j] + t - 1;
						pdp[i] = t3(a, b, j);
					}
				}
				rep(a, n) if(1<<a & j) {
					int k = i^j^1<<a;
					int t = szz(cyc2[k]);
					if(t) {
						if(dp[i] == -1 || dp[i] > dp[j] + t) {
							dp[i] = dp[j] + t;
							pdp[i] = t3(a, a, j);
						}
					}
				}
			}
			if(j == 0) break;
		}
	}
	printf("%d\n", dp[(1<<n)-1]);
	dfs((1<<n)-1);
	
	return 0;
}