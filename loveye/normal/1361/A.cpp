#include<bits/stdc++.h>
using namespace std;
const int M = 5e5 + 5,N = M;
int n,m,s[N],ans[N],vis[N],t[N];
int fir[N],to[M << 1],nxt[M << 1],cnt;
inline void addedge(int u,int v) {
	to[++cnt] = v;
	nxt[cnt] = fir[u];
	fir[u] = cnt;
}
inline bool cmp(const int &a,const int &b) {
	return t[a] < t[b];
}
int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1,u,v;i <= m;++i)
		cin >> u >> v,addedge(u,v),addedge(v,u);
	for(int i = 1;i <= n;++i)
		cin >> t[i],s[i] = i;
	sort(s+1,s+n+1,cmp);
	for(int i = 1;i <= n;++i) {
		int u = s[i],ok = 1,res = 0;
		for(int j = fir[u],v;v = to[j],j;j = nxt[j])
			if(ans[v] && !vis[ans[v]]) {
				if(ans[v] == t[u]) ok = 0,vis[ans[v]] = 1;
				else if(ans[v] < t[u]) vis[ans[v]] = 1,++res;
			}
		for(int j = fir[u],v;v = to[j],j;j = nxt[j])
			vis[ans[v]] = 0;
		ans[u] = t[u];
		if(res == t[u] - 1 && ok) continue;
		else {
			puts("-1");
			return 0;
		}
	}
	for(int i = 1;i <= n;++i)
		cout << s[i] << ' ';
	return 0;
}