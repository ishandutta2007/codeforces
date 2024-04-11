#include<bits/stdc++.h>
#define int long long
#define double long double
#define pb push_back
#define mp make_pair
#define sp ' '
#define endl '\n'
#define fi first
#define se second
using namespace std;

const int N = 105;

int n,m;
int dp[N][N][26];
vector<pair<int,int> > edge[N];

int calc(int u,int v,int c) {
    int &res = dp[u][v][c];
	if(res >= 0) return res;
	res = 0;
	for(int i = 0;i < edge[u].size();++i){
		int nxt = edge[u][i].first;
		int nc = edge[u][i].second;
		if(nc >= c) dp[u][v][c] |= calc(v, nxt, nc) ^ 1;
	}
	return res;
}
signed main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cin >> n >> m;
	while(m--) {
		int u,v;	char c;
		cin >> u >> v >> c;
		edge[u].pb(mp(v, (int) c - 'a'));
	}
	
	memset(dp, -1, sizeof dp);
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= n;++j){
			if(calc(i, j, 0)) cout << 'A';
			else cout << 'B';
		}
		cout << '\n';
	}
}