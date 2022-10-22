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

const int N=2005,MOD=998244353;
int n,a[N][N];
struct BIT {
	int c[N]; void add(int x,int v) {for(;x<=n;x+=x&-x) c[x]+=v;}
	int ask(int x) {int z(0); for(;x;x&=x-1) z+=c[x]; return z;}
} t[4];
int col[N],siz[4];
void update(int x,int dt) {
	--siz[col[x]];
	t[col[x]].add(x,-1);
	col[x]^=dt;
	++siz[col[x]];
	t[col[x]].add(x,1);
}
ll fac[N],D[N];
ll f[N][N];
int main() {
	n=read();
	fr(i,1,n) fr(j,1,n) a[i][j]=read();
	ll ans=0;
	*fac=1; fr(i,1,n) fac[i]=fac[i-1]*i%MOD;
	D[0]=1; D[1]=0; D[2]=1; fr(i,3,n) D[i]=(D[i-1]+D[i-2])*(i-1)%MOD;
	fr(i,0,n) f[i][0]=fac[i];
	fr(m,1,n) fr(i,0,n) f[i][m]=(f[i][m-1]-(i?f[i-1][m-1]:0))%MOD;
	ll pw=1;
	col[0]=1;
	rf(i,n,1) {
		ll res=0;
		fr(j,1,n) col[j]=1,t[1].add(j,1);
		siz[1]=n; siz[0]=siz[2]=siz[3]=0;
		rf(j,n,1) {
			update(a[i][j],1);
			(res+=(t[0].ask(a[i][j]-1)-(a[i-1][j]<a[i][j]&&col[a[i-1][j]]==0))*(i==1?fac[n-j]:f[n-j][n-j-siz[3]])+
				(t[2].ask(a[i][j]-1)-(a[i-1][j]<a[i][j]&&col[a[i-1][j]]==2))*(i==1?fac[n-j]:(n-j-siz[3]?f[n-j][n-j-siz[3]-1]:0)))%=MOD;
			if(i>1) update(a[i-1][j],2);
		}
		//cout<<res<<endl;
		(ans+=res*pw)%=MOD;
		fo(o,0,4) fr(j,1,n) t[o].c[j]=0;
		pw=pw*D[n]%MOD;
	}
	printf("%lld\n",ans);
	return 0;
}
int read() {
	static int x,c,f; x=0,f=1;
	do c=getchar(),(c=='-'&&(f=-1)); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}