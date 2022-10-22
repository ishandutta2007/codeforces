#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n,k,to[N << 1],nxt[N << 1],fir[N],cnt,d[N],siz[N];
long long ans;
inline void addedge(int u,int v){
	to[++cnt] = v;
	nxt[cnt] = fir[u];
	fir[u] = cnt;
}
struct Node {
	int u,w;
	bool operator < (const Node &o) const {
		return w < o.w;
	}
};
priority_queue<Node> q;
void dfs(int u,int fa) {
	siz[u] = 1;
	for(int i = fir[u],v;v = to[i],i;i = nxt[i])
		if(v != fa) d[v] = d[u] + 1,dfs(v,u),siz[u] += siz[v];
	q.push(Node{u,d[u]-siz[u]});
}
int main() {
	cin >> n >> k;
	for(int i = 1,u,v;i < n;++i)
		cin >> u >> v,addedge(u,v),addedge(v,u);
	d[1] = 1;
	dfs(1,0);
	for(int i = 1;i <= k;++i) {
		Node now = q.top();q.pop();
		ans += now.w;
	}
	cout << ans << endl;
	return 0;
}