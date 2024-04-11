#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 3e5 + 5,M = 3e5 + 5;
int n,m,A[N],B[N];
vector<int> ans[N];

vector<int> G[N];
int du[N];

int fa[N],vis[N],dfn[N],siz[N],dfc;
void dfs(int u) {
	vis[u] = 1;
	dfn[u] = ++dfc;
	siz[u] = 1;
	for(auto v : G[u]) if(!vis[v])
		fa[v] = u,dfs(v),siz[u] += siz[v];
}
int isanc(int u,int v) {
	return dfn[u] <= dfn[v] && dfn[v] < dfn[u] + siz[u];
}
vector<int> tmp;
void getpath(int id,int u,int v) {
	tmp.clear();
	while(!isanc(u,v)) {
		ans[id].push_back(u);
		u = fa[u];
	}
	while(u != v) tmp.push_back(v),v = fa[v];
	reverse(tmp.begin(),tmp.end());
	ans[id].push_back(u);
	for(auto x : tmp) ans[id].push_back(x);
}


vector<int> vec;
int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1,u,v;i <= m;++i) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1);
	int q;
	cin >> q;
	for(int i = 1,u,v;i <= q;++i) {
		cin >> u >> v;
		A[i] = u,B[i] = v;
		++du[u],++du[v];
	}
	int cnt = 0;
	fr(i,1,n) if(du[i] & 1) ++cnt;
	if(cnt) return cout << "NO\n" << cnt / 2 << endl,0;
	cout << "YES" << endl;
	fr(i,1,q) getpath(i,A[i],B[i]);
	fr(i,1,q) {
		cout << ans[i].size() << endl;
		for(auto x : ans[i]) cout << x << ' ';
		cout << endl;
	}
	return 0;
}