#include<cstdio>
#include<numeric>
#include<cassert>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cmath>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=2e5+5,MOD=998244353;
int n;
struct Edge {int v,x,y;};
vector<Edge> G[N];
int X[N],Y[N],mx[N];
ll a[N];
ll qpow(ll a,int x) {
	ll z=1;
	for(;x;x>>=1,a=a*a%MOD)
		if(x&1) z=z*a%MOD;
	return z;
}
void dfs(int u,int fa) {
	for(auto [v,x,y]:G[u]) if(v!=fa) {
		int sx=sqrt(max(x,y)),rx=x,ry=y;
		fr(i,2,sx) if(rx%i==0) {
			do rx/=i,++X[i];
			while(rx%i==0);
		}
		if(rx!=1) ++X[rx];
		fr(i,2,sx) if(ry%i==0) {
			do ry/=i,++Y[i],mx[i]=max(Y[i]-X[i],mx[i]);
			while(ry%i==0);
		}
		if(ry!=1) ++Y[ry],mx[ry]=max(mx[ry],Y[ry]-X[ry]);

		a[v]=a[u]*x%MOD*qpow(y,MOD-2)%MOD;
		dfs(v,u);
		rx=x,ry=y;
		fr(i,2,sx) if(rx%i==0) {
			do rx/=i,--X[i];
			while(rx%i==0);
		}
		if(rx!=1) --X[rx];
		fr(i,2,sx) if(ry%i==0) {
			do ry/=i,--Y[i];
			while(ry%i==0);
		}
		if(ry!=1) --Y[ry];
	}
}
int main() {
	ios::sync_with_stdio(0);
	int t; cin>>t;
	while(t--) {
		cin>>n;
		fr(i,1,n) G[i].clear();
		for(int i=1,u,v,x,y;i<n;++i) {
			cin>>u>>v>>x>>y;
			G[u].push_back((Edge){v,y,x});
			G[v].push_back((Edge){u,x,y});
		}
		fr(i,1,n) X[i]=Y[i]=mx[i]=0;
		a[1]=1;
		dfs(1,0);
		ll ans=0;
		fr(i,1,n) (ans+=a[i])%=MOD;
		fr(i,1,n) ans=ans*qpow(i,mx[i])%MOD;
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