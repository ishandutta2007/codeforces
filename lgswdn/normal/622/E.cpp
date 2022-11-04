#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+9;

struct edge {int to,nxt;}e[N*2]; int hd[N],tot;
void add(int u,int v) {e[++tot]=(edge){v,hd[u]};hd[u]=tot;}

int n,d[N],ans;
vector<int>dep;
void dfs(int u,int fa) {
	d[u]=d[fa]+1;
	bool son=0;
	for(int i=hd[u];i;i=e[i].nxt) if(e[i].to!=fa) dfs(e[i].to,u), son=1;
	if(!son) dep.push_back(d[u]);
}

signed main() {
	scanf("%lld",&n);
	for(int i=1,u,v;i<n;i++)
		scanf("%lld%lld",&u,&v), add(u,v), add(v,u);
	for(int i=hd[1];i;i=e[i].nxt) {
		int u=e[i].to;
		dep.clear();
		dfs(u,1);
		sort(dep.begin(),dep.end());
		int dept=0;
		for(int i=0;i<dep.size();i++) dept=(dept<dep[i]?dep[i]:dept+1);
		ans=max(ans,dept);
	}
	printf("%lld\n",ans);
	return 0;
}