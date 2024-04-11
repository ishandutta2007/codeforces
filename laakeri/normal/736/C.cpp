#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;

ll dp[111][30][30];//solmu, unsat dt, col dt
vector<int> g[111];

ll dp2[111][33][33];

int n,k;

pair<int, int> ns(int u, int c, int nu, int nc){
	if (u+1+nc<=k){
		u=k;
	}
	if (nu+1+c<=k){
		nu=k;
	}
	if (u==k&&nu==k) u=k;
	else if(u==k) {
		if (nu+1==k) u=k+2;
		else u=nu+1;
	}
	else if(nu==k){
	}
	else{
		if (max(u, nu+1)==k) u=k+2;
		else u=max(u, nu+1);
	}
	return {u, min(c, nc+1)};
}

void dfs(int x, int p){
	vector<int> ch;
	for (int nx:g[x]){
		if (nx!=p){
			ch.push_back(nx);
			dfs(nx, x);
		}
	}
	memset(dp2, 0, sizeof(dp2));
	dp2[0][0][k]=1;// ei oteta
	dp2[0][k][0]=1;// otetaan
	for (int a=0;a<(int)ch.size();a++){
		int c=ch[a];
		for (int i=0;i<=k;i++){
			for (int j=0;j<=k;j++){
				if (dp[c][i][j]==0) continue;
				for (int ii=0;ii<=k;ii++){
					for (int jj=0;jj<=k;jj++){
						if (dp2[a][ii][jj]==0) continue;
						auto s=ns(ii, jj, i, j);
						if (s.F>k) continue;
						if (s.S>k) s.S=k;
						dp2[a+1][s.F][s.S]+=dp[c][i][j]*dp2[a][ii][jj];
						dp2[a+1][s.F][s.S]%=mod;
					}
				}
			}
		}
	}
	for (int i=0;i<=k;i++){
		for (int j=0;j<=k;j++){
			dp[x][i][j]+=dp2[ch.size()][i][j];
			dp[x][i][j]%=mod;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	if (k==0){
		cout<<1<<endl;
		return 0;
	}
	for (int i=2;i<=n;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, 0);
	ll v=0;
	for (int i=0;i<=k;i++){
		v+=dp[1][k][i];
		v%=mod;
	}
	cout<<v<<endl;
}