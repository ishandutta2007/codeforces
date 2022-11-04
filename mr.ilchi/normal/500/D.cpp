#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000+10;

int n;
int sz[MAXN],w[MAXN],e1[MAXN],e2[MAXN];
double coeff[MAXN];
vector<int> adj[MAXN],index[MAXN];

int dfs (int v, int p){
	int ret = 1;
	for (int i=0; i<(int)adj[v].size(); i++) if (adj[v][i] != p){
		sz[index[v][i]] = dfs(adj[v][i],v);
		ret+= sz[index[v][i]];
	}
	return ret;
}

double getC (int n, int k){
	if (k == 0)
		return 1.0;
	if (n == 0)
		return 0.0;
	double ans = 1.0;
	for (int i=n-k+1; i<=n; i++)
		ans*=i;
	for (int i=2; i<=k; i++)
		ans/=i;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i=0; i<n-1; i++){
		cin >> e1[i] >> e2[i] >> w[i];
		e1[i]--; e2[i]--;
		adj[e1[i]].push_back(e2[i]); index[e1[i]].push_back(i);
		adj[e2[i]].push_back(e1[i]); index[e2[i]].push_back(i);
	}
	dfs(0,-1);
	double ans = 0.0;
	for (int i=0; i<n-1; i++){
		coeff[i] = (getC(sz[i],2)*(n-sz[i]+0.0) + getC(n-sz[i],2)*sz[i])/getC(n,3);
		coeff[i]*= 2.0;
		ans+= coeff[i] * w[i];
	}
	int que; cin >> que;
	cout << fixed << setprecision(10);
	for (int o=0; o<que; o++){
		int i,ww; cin >> i >> ww;
		i--;
		ans-= coeff[i] * w[i]; w[i] = ww;
		ans+= coeff[i] * w[i];
		cout << ans << endl;
	}
	return 0;
}