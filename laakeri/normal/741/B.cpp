#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

ll dp[1010];

int u[1010];

ll w[1010];
ll b[1010];

vector<int> g[1010];

void dfs(int x, vector<pair<ll, ll> >& ho){
	if (u[x]) return;
	u[x]=1;
	ho.push_back({w[x], b[x]});
	for (int nx:g[x]){
		dfs(nx, ho);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,ww;
	cin>>n>>m>>ww;
	for (int i=1;i<=n;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++){
		cin>>b[i];
	}
	for (int i=0;i<m;i++){
		int uu,v;
		cin>>uu>>v;
		g[uu].push_back(v);
		g[v].push_back(uu);
	}
	for (int i=1;i<=ww;i++){
		dp[i]=-1e18;
	}
	for (int i=1;i<=n;i++){
		if (u[i]==0){
			vector<pair<ll, ll> > ho;
			dfs(i, ho);
			ll bsu=0;
			ll wsu=0;
			for (auto t:ho){
				wsu+=t.F;
				bsu+=t.S;
			}
			for (int j=ww;j>=0;j--){
				if (j+wsu<=ww){
					dp[j+wsu]=max(dp[j+wsu], dp[j]+bsu);
				}
				for (auto t:ho){
					if (j+t.F<=ww){
						dp[j+t.F]=max(dp[j+t.F], dp[j]+t.S);
					}
				}
			}
		}
	}
	ll v=0;
	for (int i=0;i<=ww;i++){
		v=max(v, dp[i]);
	}
	cout<<v<<endl;
}