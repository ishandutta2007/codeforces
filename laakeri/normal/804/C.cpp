#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

vector<int> s[303030];
vector<int> g[303030];
int col[303030];

int mc=0;

void dfs(int x, int p){
	set<int> fc;
	for (int i=1;i<=(int)s[x].size();i++){
		fc.insert(i);
	}
	for (int t:s[x]) fc.erase(col[t]);
	for (int t:s[x]){
		if (col[t]==0){
			col[t]=*fc.begin();
			fc.erase(col[t]);
			mc=max(mc, col[t]);
		}
	}
	for (int nx:g[x]){
		if (nx!=p) dfs(nx, x);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		int ss;
		cin>>ss;
		for (int j=0;j<ss;j++){
			int x;
			cin>>x;
			s[i].push_back(x);
		}
	}
	for (int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, 0);
	if (mc==0) mc=1;
	cout<<mc<<'\n';
	for (int i=1;i<=m;i++){
		if (col[i]==0) col[i]=1;
		cout<<col[i]<<" ";
	}
	cout<<'\n';
}