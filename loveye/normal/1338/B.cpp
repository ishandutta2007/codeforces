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

const int N=1e5+5;
int n,rt,du[N];
int fir[N],to[N<<1],eds,nxt[N<<1];
void addedge(int u,int v) {
	to[++eds]=v;
	nxt[eds]=fir[u];
	fir[u]=eds;
	++du[v];
}
int cnt[N],c[2];
void dfs(int u,int fa,int dep) {
	if(du[u]==1) ++cnt[fa],++c[dep];
	foredge(i,u,v) if(v!=fa) {
		dfs(v,u,dep^1);
	}
}
int main() {
	cin>>n;
	for(int i=1,u,v;i<n;++i)
		cin>>u>>v,addedge(u,v),addedge(v,u);
	fr(i,1,n) if(du[i]>1) {
		rt=i; break;
	}
	dfs(rt,0,0);
	if(c[1]==0||c[0]==0) cout<<1<<' ';
	else cout<<3<<' ';
	int ans=n-1;
	fr(i,1,n) if(cnt[i]) ans-=cnt[i]-1;
	cout<<ans<<endl;
	return 0;
}

const int S = 1 << 21;
char p0[S],*p1,*p2;
#define getchar() (p2 == p1 && (p2 = (p1 = p0) + fread(p0,1,S,stdin)) == p1 ? EOF : *p1++)
inline int read() {
	static int x,c,f;x = 0;f = 1;
	do c = getchar(),c == '-' && (f = -1);while(!isdigit(c));
	do x = x * 10 + (c & 15),c = getchar();while(isdigit(c));
	return x * f;
}