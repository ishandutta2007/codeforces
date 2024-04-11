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

const int N=2e5+5,MOD=998244353;
int n,m;
int c[N];
int s[N],t[N];
ll fac[N],ifac[N];
ll qpow(ll a,int x) {
	ll z=1;
	for(;x;x>>=1,a=a*a%MOD)
		if(x&1) z=z*a%MOD;
	return z;
}
int BIT[N]; void add(int x,int v) {for(;x<=int(2e5);x+=x&-x) BIT[x]+=v;}
int ask(int x) {int z=0; for(;x;x&=x-1) z+=BIT[x]; return z;}
signed main() {
	cin>>n>>m;
	fr(i,1,n) cin>>s[i],++c[s[i]];
	fr(i,1,m) cin>>t[i];
	int lim=max(n,m);
	*fac=1; fr(i,1,lim) fac[i]=fac[i-1]*i%MOD;
	ifac[lim]=qpow(fac[lim],MOD-2);
	rf(i,lim,1) ifac[i-1]=ifac[i]*i%MOD;
	ll z=1,ans=0;
	fr(i,1,int(2e5)) {
		z=z*ifac[c[i]]%MOD;
		add(i,c[i]);
	}
	fr(i,0,min(m,n)-1) {
		if(i) {
			add(t[i],-1);
			z=z*c[t[i]]%MOD;
			if(--c[t[i]]<0) break;
		}
		(ans+=z*ask(t[i+1]-1)%MOD*fac[n-i-1])%=MOD;
	}
	if(n<m) {
		memset(c,0,sizeof c);
		fr(i,1,n) ++c[s[i]];
		fr(i,1,n) --c[t[i]];
		int ok=1;
		fr(i,1,int(2e5)) if(c[i]) ok=0;
		ans+=ok;
	}
	printf("%lld\n",(ans+MOD)%MOD);
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