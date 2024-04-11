#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n,du[N],root,d[N],ans1,ans2,dep[N];
int fir[N],to[N << 1],nxt[N << 1],cnt;
inline void addedge(int u,int v) {
	to[++cnt] = v;
	nxt[cnt] = fir[u];
	fir[u] = cnt;
	++du[v];
}
void dfs(int u,int fa) {
	int res = 0;
	for(int i = fir[u],v;v = to[i],i;i = nxt[i])
		if(v != fa) {
			dep[v] = dep[u] + 1;
			dfs(v,u);
			if(fa != root && du[v] == 1) ++res;
		}
	if(res > 0) ans2 -= res-1;
}
int main() {
	cin >> n;
	for(int i = 1,u,v;i < n;++i)
		cin >> u >> v,addedge(u,v),addedge(v,u);
	for(int i = 1;i <= n;++i)
		if(du[i] == 1) {
			root = i;
			break;
		}
	ans2 = n-1;
	dfs(root,0);
	ans1 = 1;
	for(int i = 1;i <= n;++i) {
		if(du[i] == 1 && dep[i] % 2 == 1) ans1 = 3;
		if(du[i] == 1 && dep[i] == 2) --ans2;
	}
	cout << ans1 << ' ' << ans2 << endl;
	return 0;
}