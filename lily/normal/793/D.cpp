/* Never Say Die. */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <cassert>
using namespace std;
typedef long long LL;
typedef long double LD;

#define INF 0x1f1f1f1f

int dis[81][81][81][80];
bool vis[81][81][81][80];
vector<pair <int, int> > G[81];
int n, K, m;

int solve(int x, int l, int r, int k) {
	if (k == 0) return 0;
	if (r - l + 1 < k) return INF;
	if (vis[x][l][r][k]) return dis[x][l][r][k];
	vis[x][l][r][k] = 1;
	int &ret = dis[x][l][r][k];
	ret = INF;
	for (int i = 0; i < (int)G[x].size(); i++) {
		if (G[x][i].first >= l && G[x][i].first <= r){
			ret = min(ret, solve(G[x][i].first, l, G[x][i].first - 1, k - 1) + G[x][i].second); 
			ret = min(ret, solve(G[x][i].first, G[x][i].first + 1, r, k - 1) + G[x][i].second); 
		}
	}
	return ret;
}

int main() {
	cin >> n >> K >> m;
	for (int i = 1, u, v, c; i <= m; i++) {
		cin >> u >> v >> c;
		G[u].push_back(make_pair(v, c));
	}
	int ans = INF;
	for (int i = 1; i <= n; i++) {
		ans = min(ans, solve(i, 1, i - 1, K - 1));
		ans = min(ans, solve(i, i + 1, n, K - 1));
	}
	if (ans < INF) printf("%d\n", ans);
	else printf("-1\n");

	return 0;
}