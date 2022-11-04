/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <complex>
#include <stack>
#include <deque>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

const int MAXN = 5000+10;

bool ans[MAXN],mark[MAXN];
bool dp[MAXN][MAXN];
int n;
vector <int> adj[MAXN];

int dfs (int v){
	mark[v] = true;
	int ret = 1;
	dp[v][0] = true;
	for (int i=0; i<(int)adj[v].size(); i++){
		int tmp = adj[v][i];
		if (!mark[tmp]){
			int sz = dfs(tmp);
			ret+=sz;
			for (int i=n-1; i>=sz; i--) if (dp[v][i-sz])
				ans[i] = dp[v][i] = true;
		}		
	}
	for (int i=n-1; i>=n-ret; i--) if (dp[v][i-(n-ret)])
		ans[i] = dp[v][i] = true;
	return ret;
}

int main(){
	cin >> n;
	for (int i=1; i<n; i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1);
	int cnt = 0;
	for (int i=1; i<n-1; i++) if (ans[i]) 
		cnt++;
	cout << cnt << endl;
	for (int i=1; i<n-1; i++) if (ans[i])
		cout << i << ' ' << n-1-i << endl;
	return 0;
}