#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

vector<int> g[1010101];
int perm[1010101];
int v[1010101];
int u[1010101];

void dfs(int x, vector<int>& ps, vector<int>& vs){
	if (u[x]) return;
	u[x]=1;
	ps.push_back(x);
	vs.push_back(perm[x]);
	for (int nx:g[x]){
		dfs(nx, ps, vs);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>perm[i];
	}
	for (int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i=1;i<=n;i++){
		if(u[i]) continue;
		vector<int> ps;
		vector<int> vs;
		dfs(i, ps, vs);
		sort(ps.begin(), ps.end());
		sort(vs.rbegin(), vs.rend());
		for (int j=0;j<(int)ps.size();j++){
			v[ps[j]]=vs[j];
		}
	}
	for (int i=1;i<=n;i++){
		cout<<v[i]<<" ";
	}
}