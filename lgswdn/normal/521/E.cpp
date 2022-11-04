// LUOGU_RID: 90782274
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;

struct edge {int to,nxt;}e[N*2]; int hd[N],tot;
void add(int u,int v) {e[++tot]=(edge){v,hd[u]};hd[u]=tot;}

int n,m,d[N],f[N],u1,v1,u2,v2,l[N],r[N];
bool vst[N],in[N],flag;
void dfs(int u,int fa) {
	vst[u]=in[u]=1, d[u]=d[fa]+1, f[u]=fa;
	for(int i=hd[u],v;i;i=e[i].nxt) {
		if((v=e[i].to)==fa) continue;
		else if(!vst[v]) dfs(v,u);
		else if(in[v]) {
			for(int p=u;p!=v;p=f[p]) {		// 
				//lr 
				if(!l[p]||!r[p]) l[p]=u, r[p]=v;	// 
				else {								//
					u1=r[p], u2=v, v1=l[p], v2=u;
					//cout<<u1<<" "<<u2<<" "<<v1<<" "<<v2<<endl;
					flag=1; return;
				}
			}
		}
		if(flag) return;
	}
	in[u]=0;
}
vector<int>route;
int lca(int u,int v) {
	if(d[u]<d[v]) swap(u,v);
	while(d[u]>d[v]) u=f[u];
	while(u!=v) u=f[u], v=f[v];
	return u;
}
void find(int u,int v) {
	for(int p=u;p!=v;p=f[p]) route.push_back(p);
	route.push_back(v);
}
void write(bool type) {
	printf("%d ",route.size());
	if(type==0) for(int i=0;i<route.size();i++) printf("%d ",route[i]);
	else for(int i=route.size()-1;i>=0;i--) printf("%d ",route[i]);
	puts("");
	route.clear();
}
void print() {
	if(!u1||!u2||!v1||!v2) {puts("NO"); return;}
	puts("YES");
	if(d[u1]<d[u2]) swap(u1,u2), swap(v1,v2);
	int la=lca(v1,v2);
	//cout<<la<<endl;
	find(la,u1); write(1);
	route.push_back(u1), find(v1,la); write(0);
	find(u1,u2), find(v2,la); write(0);
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++) scanf("%d%d",&u,&v), add(u,v), add(v,u);
	for(int i=1;i<=n;i++) if(!vst[i]&&!flag) dfs(i,0);
	print();
	return 0;
}