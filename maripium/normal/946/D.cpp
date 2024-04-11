#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 505;
const int INF = 123456789;

int n,m,k;
string s;
int dp[N][N];
int esc[N][N];

signed main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);
	memset(dp,INF,sizeof dp);
	memset(esc,INF,sizeof esc);
	cin >> n >> m >> k;
	for(int i = 1;i <= n;++i) {
		cin >> s;
		vector<int> les(0);
		for(int j = 0;j < m;++j) {
			if(s[j] == '1') les.push_back(j);
		}
		
		esc[i][les.size()] = 0;
		for(int l = 0;l < les.size();++l) 
		     for(int r = l;r < les.size();++r)  
			      esc[i][l + les.size() - 1 - r] = min(esc[i][l + les.size() - 1 - r],les[r] - les[l] + 1);
	}
	
	dp[0][0] = 0;
	for(int i = 1;i <= n;++i) 
		for(int j = 0;j <= k;++j) 
			for(int l = 0;l + j <= k;++l) 
				dp[i][l + j] = min(dp[i][l + j],dp[i - 1][j] + esc[i][l]);
	
	int ans = INF;
	for(int i = 0;i <= k;++i) ans = min(ans,dp[n][i]);
	cout << ans << endl;
}