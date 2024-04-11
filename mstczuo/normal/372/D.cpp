# include <iostream>
# include <cstdio>
# include <vector>
# include <cstring>
# include <set>

const int MAXN = int(1e5)+10, Log = 20;
using namespace std;

int anc[MAXN][Log], dep[MAXN];
int seq[MAXN], at[MAXN];
vector<int> E[MAXN];
set<int> st;

void dfs(int u,int p,int d) {
	static int cnt = 0; int t = p;
	anc[u][0] = p; seq[cnt] = u; at[u] = cnt++; 
	for(int i=1; i<Log; i++) anc[u][i] = (t==-1) ? t: (t = anc[t][i-1]);
	for(vector<int>::iterator it=E[u].begin(); it!=E[u].end(); it++)
		if (*it != p) dfs(*it, u, dep[*it] = d+1);
}

int lca(int u,int v) {
	if (dep[u] < dep[v]) swap(u,v); int up = dep[u] - dep[v];
	for(int i=0; i<Log; i++) if((up>>i)&1) u=anc[u][i];
	for(int i=Log-1; i>=0; i--) 
		if(anc[u][i]!=anc[v][i]) u=anc[u][i],v=anc[v][i];
	return (u==v)?u:anc[u][0];
}

int add(int u) {
	if (st.empty()) return 1;
	set<int>::iterator it = st.lower_bound(at[u]);
	int L, R;
	R = seq[it == st.end()?*st.begin():*it];
	L = seq[it == st.begin()?*st.rbegin():*--it];
	return dep[u]-dep[lca(u,L)]-dep[lca(u,R)]+dep[lca(L,R)];
}

int main() {
	int n, limit, x, y;
	scanf("%d%d", &n,&limit);
	for(int i=0; i<n-1; i++) scanf("%d%d",&x,&y),
		E[x-1].push_back(y-1),E[y-1].push_back(x-1);

	dfs(0, -1, 0);

	int i=0, j=0, cur=0, ans=0;
	for(i=0; i<n; st.erase(at[i]), cur-=add(i++)) 
		while(cur<=limit) { 
			ans = max(ans,j-i); if(j==n) break;
			cur += add(j),st.insert(at[j++]);
		}
	printf("%d\n",ans);
}