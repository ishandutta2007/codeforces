#include<cstdio>
#include<map>
#include<queue>
#include<numeric>
#include<cassert>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)
#define fi first
#define se second

const int N=3e5+605;
int n,m,a[N],nds=600,del[N],mex=1;
int getmex() {while(del[mex]) ++mex; del[mex]=1; return mex;}
vector<int> G1[N],G2[N];
void addedge(int u,int v) {
	if(del[v]||del[u]) return;
	if(u>600) {
		G1[u].push_back(v);
		G1[v].push_back(u);
	} else {
		G2[u].push_back(v);
		G2[v].push_back(u);
	}
}//G1 is bipartite graph

int match[N],vis[N];
int dfs(int u) {
	if(vis[u]) return 0;
	vis[u]=1;
	for(auto v:G1[u]) {
		if(!match[v]||dfs(match[v])) {
			match[match[u]=v]=u;
			return 1;
		}
	} return 0;
}
queue<int> q;
int f[N]; int getf(int x) {return x==f[x]?x:f[x]=getf(f[x]);}
int col[N],pre[N];
int tim[N],timc;
int LCA(int u,int v) {
	for(++timc;tim[u]!=timc;swap(u,v)) {
		if(!u) continue;
		tim[u]=timc;
		u=pre[match[u]];
	} return u;
}
void blossom(int u,int v,int lca) {
	for(;getf(u)!=lca;u=pre[v]) {
		pre[u]=v;
		v=match[u];
		if(col[v]==2) col[v]=1,q.push(v);
		f[u]=f[v]=lca;
	}
}
int chk(int u,int v) {
	if(!col[v]) {
		pre[v]=u;
		if(!match[v]) {
			for(;v;v=u) {
				u=match[pre[v]];
				match[match[v]=pre[v]]=v;
			} return 1;
		}
		col[v]=2,col[match[v]]=1;
		q.push(match[v]);
	} else if(col[v]==col[u]&&getf(u)!=getf(v)) {
		int lca=LCA(u,v);
		blossom(u,v,lca);
		blossom(v,u,lca);
	} return 0;
}
void bfs(int s) {
	fr(i,1,nds) col[i]=pre[i]=0,f[i]=i;
	while(!q.empty()) q.pop();
	q.push(s); col[s]=1;
	while(!q.empty()) {
		int u=q.front(); q.pop();
		for(auto v:G1[u]) if(chk(u,v)) return;
		for(auto v:G2[u]) if(chk(u,v)) return;
	}
}
void Match() {
	fr(i,1,600) if(!del[i]&&!match[i])
		memset(vis,0,sizeof vis),dfs(i);
	fr(i,1,600) if(!del[i]&&!match[i]) bfs(i);
}

map<pair<int,int>,int> id;
void construct() {
	int sdn=600,lst=0;
	fr(i,1,n) if(a[i]) lst=i;
	else if(i==n||a[i+1]) {
		if(i-lst&1) {
			++sdn;
			if(lst&&match[sdn]==a[lst]) del[a[lst]]=1;
			else if(i<n&&match[sdn]==a[i+1]) del[a[i+1]]=1;
		} else if(lst&&i<n&&a[lst]!=a[i+1]) {
			pair<int,int> z(a[lst],a[i+1]);
			if(z.fi>z.se) swap(z.fi,z.se);
			if(id[z]==i&&match[z.fi]==z.se)
				del[a[lst]]=del[a[i+1]]=1;
		}
	}
	sdn=600,lst=0;
	fr(i,1,n) if(a[i]) lst=i;
	else if(i==n||a[i+1]) {
		if(i-lst&1) {
			++sdn;
			if(lst&&match[sdn]==a[lst]) {
				a[lst+1]=a[lst];
				for(int j=lst+2;j<=i;j+=2)
					a[j]=a[j+1]=getmex();
			}
			else if(i<n&&match[sdn]==a[i+1]) {
				a[i]=a[i+1];
				for(int j=lst+1;j<i;j+=2)
					a[j]=a[j+1]=getmex();
			} else {
				for(int j=lst+1;j<i;j+=2) a[j]=a[j+1]=getmex();
				a[i]=1;
			}
		} else {
			if(lst&&i<n&&a[lst]!=a[i+1]) {
				pair<int,int> z(a[lst],a[i+1]);
				if(z.fi>z.se) swap(z.fi,z.se);
				if(id[z]==i&&match[z.fi]==z.se) {
					a[lst+1]=a[lst]; a[i]=a[i+1];
					for(int j=lst+2;j<i;j+=2) a[j]=a[j+1]=getmex();
				} else for(int j=lst+1;j<=i;j+=2) a[j]=a[j+1]=getmex();
			} else for(int j=lst+1;j<=i;j+=2) a[j]=a[j+1]=getmex();
		}
	}
}
int main() {
	scanf("%d",&n);
	fr(i,1,n) scanf("%d",a+i);
	fo(i,1,n) if(a[i]&&a[i]==a[i+1]) del[a[i]]=1;
	int lst=0;
	fr(i,1,n) if(a[i]) lst=i;
	else if(i==n||a[i+1]) {
		if(i-lst&1) {
			++nds;
			if(lst) addedge(nds,a[lst]);
			if(i<n) addedge(nds,a[i+1]);
		} else if(lst&&i<n) {
			pair<int,int> z(a[lst],a[i+1]);
			if(z.fi==z.se) continue;
			if(z.fi>z.se) swap(z.fi,z.se);
			if(!id[z]) id[z]=i,addedge(a[lst],a[i+1]);
		}
	}
	Match();
	construct();
	fr(i,1,n) printf("%d ",a[i]);
	return 0;
}

const int S=1<<21;
char p0[S],*p1,*p2;
#define getchar() (p2==p1&&(p2=(p1=p0)+fread(p0,1,S,stdin))==p1?EOF:*p1++)
inline int read() {
	static int x,c,f;x=0;f=1;
	do c=getchar(),c=='-'&&(f=-1); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}