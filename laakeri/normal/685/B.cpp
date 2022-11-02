#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int aps[303030];

vector<int> g[303030];

void dfs1(int x, int p){
	aps[x]=1;
	for (int nx:g[x]){
		if (nx!=p){
			dfs1(nx, x);
			aps[x]+=aps[nx];
		}
	}
}

int v[303030];

set<pair<int, int> > qq;

void dfs2(int x, int p){
	vector<pair<int, int> > ne;
	int ms=0;
	for (int nx:g[x]){
		if (nx!=p){
			ne.push_back({aps[nx], nx});
			ms=max(ms, aps[nx]);
		}
	}
	sort(ne.rbegin(), ne.rend());
	qq.insert({aps[x]/2, x});
	while ((int)qq.size()>0&&(*qq.rbegin()).F>=ms){
		auto t=qq.rbegin();
		v[(*t).S]=x;
		qq.erase((*t));
	}
	for (auto t:ne){
		dfs2(t.S, x);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,q;
	cin>>n>>q;
	for (int i=2;i<=n;i++){
		int p;
		cin>>p;
		g[p].push_back(i);
		g[i].push_back(p);
	}
	dfs1(1, 0);
	dfs2(1, 0);
	for (int i=0;i<q;i++){
		int x;
		cin>>x;
		cout<<v[x]<<'\n';
	}
}