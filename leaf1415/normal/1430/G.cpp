#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e9
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;

llint n, m;
vector<int> G[20];
int a[20], asum[1<<18];
int r[20], rsum[1<<18];
int dp[2][1<<18][19];
int rec[19][1<<18][19];
int ans[20];
bool used[20];
vector<int> topo;

int dfs(int v)
{
	llint ret = 1<<v;
	used[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		if(!used[G[v][i]]) ret |= dfs(G[v][i]);
	}
	return ret;
}

void tpsort(int v)
{
	used[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		if(!used[G[v][i]]) tpsort(G[v][i]);
	}
	topo.push_back(v);
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	llint u, v, w;
	for(int i = 0; i < m; i++){
		cin >> u >> v >> w;
		u--, v--;
		a[u] += w, a[v] -= w;
		G[u].push_back(v);
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++) used[j] = false;
		r[i] = dfs(i);
	}
	
	for(int i = 0; i < n; i++) used[i] = false;
	for(int i = 0; i < n; i++) if(!used[i]) tpsort(i);
	reverse(topo.begin(), topo.end());
	
	llint N = 1<<n;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < n; j++){
			if(i & (1<<j)){
				asum[i] += a[j];
				rsum[i] |= r[j];
			}
		}
	}
	for(int k = 0; k < 2; k++){
		for(int i = 0; i < N; i++){
			for(int j = 0; j <= n; j++){
				dp[k][i][j] = inf;
			}
		}
	}
	dp[0][0][0] = 0;
	
	for(int k = 0; k < n; k++){
		for(int i = 0; i < N; i++){
			for(int j = 0; j <= n; j++){
				if(j == 0) continue;
				dp[k&1][i][j] = inf;
			}
		}
		for(int j = 0; j < n; j++){
			int v = topo[j];
			for(int i = 0; i < N; i++){
			if((rsum[i] & i) != rsum[i]) continue;
				if(dp[k&1][i][j+1] > dp[k&1][i][j]){
					dp[k&1][i][j+1] = dp[k&1][i][j];
					rec[k][i][j+1] = 0;
				}
				if((i & (1<<v)) == 0 && (r[v] & (i | (1<<v))) == r[v]){
					if(dp[k&1][i|(1<<v)][j+1] > dp[k&1][i][j] + a[v] * k){
						dp[k&1][i|(1<<v)][j+1] = dp[k&1][i][j] + a[v] * k;
						rec[k][i|(1<<v)][j+1] = v+1;
					}
				}
			}
		}
		for(int i = 0; i < N; i++) dp[(k+1)&1][i][0] = dp[k&1][i][n];
	}
	
	int i = N-1;
	for(int k = n-1; k >= 0; k--){
		for(int j = n; j > 0; j--){
			llint ni = rec[k][i][j];
			if(ni == 0) continue;
			ni--;
			ans[ni] = k;
			i &= ~(1<<ni);
		}
	}
	for(int i = 0; i < n; i++) cout << ans[i] << " "; cout << endl;
	
	return 0;
}