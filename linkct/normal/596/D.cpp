#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 2005;

int n, h, lft[MAXN], rht[MAXN], pos[MAXN];
double dp[MAXN][MAXN][2][2], p;
bool vis[MAXN][MAXN][2][2];

double dfs(int l, int r, bool x, bool y){
	if(r < l) return 0.0;
	if(vis[l][r][x][y]) return dp[l][r][x][y];
	vis[l][r][x][y] = true;
	double &now = dp[l][r][x][y];
	//left tree falls to left
	if(x) now += (dfs(l + 1, r, false, y) + min(pos[l] - pos[l - 1] - h, h)) * 0.5 * p;
	else now += (dfs(l + 1, r, false, y) + min(pos[l] - pos[l - 1], h)) * 0.5 * p;
	//left tree falls to right
	if(rht[l] < r) now += (dfs(rht[l] + 1, r, true, y) + pos[rht[l]] - pos[l] + h) * 0.5 * (1.0 - p);
	else if(y) now += (pos[r] - pos[l] + min(pos[r + 1] - pos[r] - h, h)) * 0.5 * (1.0 - p);
	else now += (pos[r] - pos[l] + min(pos[r + 1] - pos[r], h)) * 0.5 * (1.0 - p);
	//right tree falls to left
	if(lft[r] > l) now += (dfs(l, lft[r] - 1, x, true) + pos[r] - pos[lft[r]] + h) * 0.5 * p;
	else if(x) now += (pos[r] - pos[l] + min(pos[l] - pos[l - 1] - h, h)) * 0.5 * p;
	else now += (pos[r] - pos[l] + min(pos[l] - pos[l - 1], h)) * 0.5 * p;
	//right tree falls to right
	if(y) now += (dfs(l, r - 1, x, false) + min(pos[r + 1] - pos[r] - h, h)) * 0.5 * (1.0 - p);
	else now += (dfs(l, r - 1, x, false) + min(pos[r + 1] - pos[r], h)) * 0.5 * (1.0 - p);
	return now;
}
int main(){
	int i;
	scanf("%d%d%lf", &n, &h, &p);
	for(i = 1; i <= n; ++ i) scanf("%d", &pos[i]);
	sort(pos + 1, pos + 1 + n);
	pos[0] = - 200000005, pos[n + 1] = 200000005;
	for(i = 1; i <= n; ++ i){
		lft[i] = upper_bound(pos + 1, pos + 1 + n, pos[i] - h) - pos;
		if(lft[i] != i) lft[i] = lft[lft[i]];
	}
	for(i = n; i; -- i){
		rht[i] = lower_bound(pos + 1, pos + 1 + n, pos[i] + h) - pos - 1;
		if(rht[i] != i) rht[i] = rht[rht[i]];
	}
	printf("%.12f\n", dfs(1, n, 0, 0));
	return 0;
}