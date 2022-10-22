#include<bits/stdc++.h>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(file) freopen(file".in","r",stdin)
#define fileout(file) freopen(file".out","w",stdout)

const int N=505,M=2.5e5+5;
int n,m;
int fir[N],to[M<<1],eds,nxt[M<<1],wei[M<<1];
void addedge(int u,int v,int w) {
	to[++eds]=v;
	wei[eds]=w;
	nxt[eds]=fir[u];
	fir[u]=eds;
}
int f[N][N];
void bfs(int s,int *d) {
	fr(i,1,n) d[i]=-1;
	queue<int> q;
	q.push(s); d[s]=0;
	while(!q.empty()) {
		int u=q.front(); q.pop();
		foredge(i,u,v) if(d[v]==-1)
			q.push(v),d[v]=d[u]+1;
	}
}
int main() {
	int T=read();
	while(T--) {
		n=read(),m=read();
		fr(i,1,n) fir[i]=0; eds=0;
		fr(i,1,n) fr(j,1,n) f[i][j]=0x3f3f3f3f;
		fr(i,1,n) f[i][i]=0;
		for(int i=1,u,v,w;i<=m;++i) {
			u=read(),v=read(),w=read();
			f[u][v]=f[v][u]=1;
			addedge(u,v,w);
			addedge(v,u,w);
		}
		fr(k,1,n) fr(i,1,n) fr(j,1,n)
			f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		ll ans=9e18;
		fr(u,1,n) foredge(i,u,v) {
			ans=min(ans,1ll*(f[1][u]+f[n][v]+1)*wei[i]);
			//if(ans==132) cout<<u<<' '<<v<<endl;
			fr(w,1,n) {
				ans=min(ans,1ll*(f[w][u]+1+f[w][1]+f[w][n]+1)*wei[i]);
				//if(ans==132) cout<<u<<' '<<v<<' '<<w<<endl;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
int read() {
	static int x,c,f; x=0,f=1;
	do c=getchar(),(c=='-'&&(f=-1)); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}