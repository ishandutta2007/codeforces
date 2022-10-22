#include<cstdio>
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

const int N=1e5+5;
int t,n,a,b,da,db;
int fir[N],to[N<<1],eds,nxt[N<<1];
void addedge(int u,int v) {
	to[++eds]=v;
	nxt[eds]=fir[u];
	fir[u]=eds;
}
int bz[N][20],dep[N];
void dfs(int u) {
	dep[u]=dep[bz[u][0]]+1;
	fr(i,1,17) bz[u][i]=bz[bz[u][i-1]][i-1];
	foredge(i,u,v) if(v!=bz[u][0]) {
		bz[v][0]=u;
		dfs(v);
	}
}
int LCA(int u,int v) {
	if(dep[u]<dep[v]) swap(u,v);
	rf(i,17,0) if(dep[u]-dep[v]>>i&1) u=bz[u][i];
	if(u==v) return u;
	rf(i,17,0) if(bz[u][i]!=bz[v][i]) u=bz[u][i],v=bz[v][i];
	return bz[u][0];
}
int dis(int u,int v) {return dep[u]+dep[v]-(dep[LCA(u,v)]<<1);}
int main() {
	cin>>t;
	while(t--) {
		cin>>n>>a>>b>>da>>db;
		eds=0; fr(i,1,n) fir[i]=0;
		for(int i=1,u,v;i<n;++i) {
			cin>>u>>v;
			addedge(u,v);
			addedge(v,u);
		}
		bz[1][0]=0; dfs(1);
		int A=max_element(dep+1,dep+n+1)-dep;
		bz[A][0]=0; dfs(A);
		int len=(*max_element(dep+1,dep+n+1))-1;
		if(db<=2*da||len<=2*da||dis(a,b)<=da) cout<<"Alice"<<endl;
		else cout<<"Bob"<<endl;
	}
	return 0;
}

const int S = 1 << 21;
char p0[S],*p1,*p2;
#define getchar() (p2==p1&&(p2=(p1=p0)+fread(p0,1,S,stdin))==p1?EOF:*p1++)
inline int read() {
	static int x,c,f;x=0;f=1;
	do c=getchar(),c=='-'&&(f=-1); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}