/*input
30 2
010101010101010010101010101010
110110110110110011011011011011
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;

int m,n;
string s[55];
int dp[1005][1005];
int par[1005];
int cnt[1005];
int ans = 1;

int fin(int u) { 
    return par[u] == u ? u : par[u] = fin(par[u]);
}
void uni(int u,int v) { 
     par[fin(u)] = fin(v);
}

signed main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cin >> m >> n;
	for(int i = 0;i < n;++i) cin >> s[i];
	for(int i = 0;i < m;++i) par[i] = i;
	for(int i = 0;i < m;++i) {
		for(int j = i + 1;j < m;++j) {
			bool ok = true;
			for(int k = 0;k < n;++k) {
				if(s[k][i] != s[k][j]) ok = false;
			}
			if(ok) uni(i,j);
		}
	}
	
	dp[0][0] = 1;
	for(int i = 1;i <= m;++i) {
		for(int j = 1;j <= i;++j) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] * j) % mod;
		}
	}
	for(int i = 0;i < m;++i) ++cnt[fin(i)];
	for(int i = 0;i < m;++i) {
		if(not cnt[i]) continue;
		int cur = 0;
		for(int group = 1;group <= cnt[i];++group) cur = (cur + dp[cnt[i]][group]) % mod;
		ans = (ans * cur) % mod;
	}
	cout << ans << endl;
}