#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

vector<pair<int, int> > g[202020];
int r[202020];

vector<int> ss[202020];

int c[202020];

void dfs(int x, int cc){
	if (c[x]){
		if (c[x]!=cc){
			cout<<"NO"<<endl;
			exit(0);
		}
		return;
	}
	c[x]=cc;
	for (auto nx:g[x]){
		if (nx.S==0){
			dfs(nx.F, cc);
		}
		else{
			dfs(nx.F, 3-cc);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>r[i];
		r[i]=1-r[i];
	}
	for (int i=1;i<=m;i++){
		int x;
		cin>>x;
		for (int j=0;j<x;j++){
			int a;
			cin>>a;
			ss[a].push_back(i);
		}
	}
	for (int i=1;i<=n;i++){
		assert(ss[i].size()==2);
		g[ss[i][0]].push_back({ss[i][1], r[i]});
		g[ss[i][1]].push_back({ss[i][0], r[i]});
	}
	for (int i=1;i<=m;i++){
		if (c[i]==0){
			dfs(i, 1);
		}
	}
	cout<<"YES"<<endl;
}