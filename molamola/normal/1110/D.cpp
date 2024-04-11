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
#define pb(x) push_back(x)
#define szz(x) (int)x.size()
#define sz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;

int cnt[1000010];
int dp[1000010][5][3];

void upd(int &a, int b) {
	if(a < b) a = b;
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++) {
		int x; scanf("%d", &x);
		cnt[x]++;
	}
	int ans = 0;
	rep(i, 1000010) rep(j, 5) rep(k, 3) dp[i][j][k] = -1e9;
	dp[0][0][0] = 0;
	for(int i=0;i<m;i++) rep(j, 5) rep(k, 3) if(dp[i][j][k] >= 0) {
		int x = cnt[i+1];
		int a = min({x, k, j});
		for(int b=0;b<=a;b++) {
			int r = (x - b) % 3;
			int v = (x - b) / 3 + b;
			int nk = min(j-b, 2);
			upd(dp[i+1][r][nk], dp[i][j][k] + v);
			if(r < x - b) {
				r += 3;
				--v;
				upd(dp[i+1][min(r,4)][nk], dp[i][j][k] + v);
				if(r < x - b) {
					r += 3;
					--v;
					upd(dp[i+1][min(r,4)][nk], dp[i][j][k] + v);
				}
			}
		}
	}
	rep(i, 5) rep(j, 3) ans = max(ans, dp[m][i][j]);
	printf("%d\n", ans);
	
	return 0;
}