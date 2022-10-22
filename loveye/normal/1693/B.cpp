#include<cstdio>
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

const int N=2e5+5;
int n,fa[N],l[N],r[N];
ll f[N];
vector<int> G[N];
int ans;
void dfs(int u) {
	f[u]=0;
	for(auto v:G[u]) {
		dfs(v);
		f[u]+=f[v];
	}
	if(f[u]>=l[u]) f[u]=min(f[u],r[u]+0ll);
	else f[u]=r[u],++ans;
}
int main() {
	ios::sync_with_stdio(0);
	int t; cin>>t;
	while(t--) {
		cin>>n;
		fr(i,1,n) G[i].clear();
		fr(i,2,n) cin>>fa[i],G[fa[i]].push_back(i);
		fr(i,1,n) cin>>l[i]>>r[i];
		ans=0; dfs(1);
		cout<<ans<<endl;
	}
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