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
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define pback push_back
#define inf 1e18
#define mod 1000000007

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;

llint n, m, c;
vector<llint> G[2005];
llint dp[2005][4005];
int ldp[2005][8005], rdp[2005][8005];
llint zero = 4002;
bool used[2005];

llint dfs(int v)
{
	used[v] = true;
	rep(i, 0, (int)G[v].size()-1){
		if(used[G[v][i]]) continue;
		return dfs(G[v][i]) + 1;
	}
	return 1;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	llint u, v;
	rep(i, 1, m){
		cin >> u >> v;
		G[u].pback(v);
		G[v].pback(u);
	}
	
	vector<llint> vec;
	used[1] = true;
	rep(i, 0, (int)G[1].size()-1){
		llint v = G[1][i];
		if(used[v]) continue;
		vec.pback(dfs(v)+1);
	}
	c = vec.size();
	
	dp[0][0] = 1;
	rep(i, 0, c-1){
		rep(j, 0, m){
			(dp[i+1][j] += dp[i][j]) %= mod;
			if(j+vec[i] <= m) (dp[i+1][j+vec[i]] += dp[i][j]) %= mod;
		}
	}
	
	ldp[0][zero] = 1;
	rep(i, 0, c-1){
		rep(j, -m, m){
			(ldp[i+1][zero+j] += ldp[i][zero+j]) %= mod;
			if(j+vec[i] <= m) (ldp[i+1][zero+j+vec[i]] += ldp[i][zero+j]) %= mod;
			if(j-vec[i] >= -m) (ldp[i+1][zero+j-vec[i]] += ldp[i][zero+j]) %= mod;
		}
	}
	
	rdp[c+1][zero] = 1;
	for(int i = c+1; i >= 2; i--){
		rep(j, -m, m){
			(rdp[i-1][zero+j] += rdp[i][zero+j]) %= mod;
			if(j+vec[i-2] <= m) (rdp[i-1][zero+j+vec[i-2]] += rdp[i][zero+j]) %= mod;
			if(j-vec[i-2] >= -m) (rdp[i-1][zero+j-vec[i-2]] += rdp[i][zero+j]) %= mod;
		}
	}
	
	/*rep(i, 0, c){
		rep(j, -n, n){
			cout << ldp[i][zero+j] << " ";
		}
		cout << endl;
	}*/
	
	llint ans = 0;
	if(m % 2 == 0) ans += dp[c][m/2];
	rep(i, 1, c)
	{
		for(int j = vec[i-1]-2; j >= -vec[i-1]+2; j--){
			rep(k, -m, m){
				if(k+j < -m || k+j > m) continue;
				ans += (llint)ldp[i-1][zero+k] * (llint)rdp[i+1][zero+k+j] % mod * 2 % mod;
				ans %= mod;
			}
		}
	}
	
	if(m % 2){
		rep(i, 0, c+1){
			rep(j, -m, m){
				ldp[i][zero+j] = rdp[i][zero+j] = 0;
			}
		}
		
		ldp[0][zero] = 1;
		rep(i, 0, c-1){
			rep(j, -m, m){
				if(j+vec[i] <= m) (ldp[i+1][zero+j+vec[i]] += ldp[i][zero+j]) %= mod;
				if(j-vec[i] >= -m) (ldp[i+1][zero+j-vec[i]] += ldp[i][zero+j]) %= mod;
			}
		}
		
		rdp[c+1][zero] = 1;
		for(int i = c+1; i >= 2; i--){
			rep(j, -m, m){
				if(j+vec[i-2] <= m) (rdp[i-1][zero+j+vec[i-2]] += rdp[i][zero+j]) %= mod;
				if(j-vec[i-2] >= -m) (rdp[i-1][zero+j-vec[i-2]] += rdp[i][zero+j]) %= mod;
			}
		}
		
		rep(i, 1, c)
		{
			llint j = vec[i-1]-1;
			rep(k, -m, m){
				if(k+j < -m || k+j > m) continue;
				ans += (llint)ldp[i-1][zero+k] * (llint)rdp[i+1][zero+k+j] % mod * 2 % mod;
				ans %= mod;
			}
			j = -vec[i-1]+1;
			rep(k, -m, m){
				if(k+j < -m || k+j > m) continue;
				ans += (llint)ldp[i-1][zero+k] * (llint)rdp[i+1][zero+k+j] % mod * 2 % mod;
				ans %= mod;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}