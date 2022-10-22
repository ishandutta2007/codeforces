#include<cstdio>
#include<map>
#include<cassert>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=2e5+5,M=3005,MOD=998244353,B=1e7;
int n,m;
int a[N],w[N];
ll fac[M],ifac[M];
ll dp[M][M];
ll sum[2];
ll qpow(ll a,int x) {
	ll z=1;
	for(;x;x>>=1,a=a*a%MOD)
		if(x&1) z=z*a%MOD;
	return z;
}
ll C(int n,int m) {
	if(n<m) return 0;
	return fac[n]*ifac[m]%MOD*ifac[n-m]%MOD;
}
ll _inv[B+5];
ll inv(ll x) {return x<=B?_inv[x]:-_inv[MOD%x]*(MOD/x)%MOD;}
map<int,ll> ansd,ansl;
int main() {
	cin>>n>>m;
	fr(i,1,n) cin>>a[i];
	fr(i,1,n) {
		cin>>w[i];
		sum[a[i]]+=w[i];
		if(a[i]) ansl[w[i]]=0;
		else ansd[w[i]]=0;
	}
	_inv[1]=1; fr(i,2,B) _inv[i]=-_inv[MOD%i]*(MOD/i)%MOD;
	fac[0]=1; fr(i,1,m) fac[i]=fac[i-1]*i%MOD;
	ifac[m]=qpow(fac[m],MOD-2);
	rf(i,m,1) ifac[i-1]=ifac[i]*i%MOD;

	dp[0][0]=1;
	fo(i,0,m) fr(j,0,i) if(dp[i][j]) {
		(dp[i+1][j+1]+=dp[i][j]*(sum[0]-j)%MOD*inv(sum[0]+sum[1]-j+i-j))%=MOD;
		(dp[i+1][j]+=dp[i][j]*(sum[1]+i-j)%MOD*inv(sum[0]+sum[1]-j+i-j))%=MOD;
	}
	for(auto &p:ansd) {
		ll c=p.first;
		ll &ans=p.second; ans=0;
		fr(i,0,m) (ans+=dp[m][i]*c%MOD*(sum[0]-i)%MOD*inv(sum[0]))%=MOD;
	}
	//dislike
	memset(dp,0,sizeof dp);
	dp[0][0]=1;
	fo(i,0,m) fr(j,0,i) if(dp[i][j]) {
		(dp[i+1][j+1]+=dp[i][j]*(sum[1]+j)%MOD*inv(sum[0]+sum[1]+j-(i-j)))%=MOD;
		(dp[i+1][j]+=dp[i][j]*(sum[0]-(i-j))%MOD*inv(sum[0]+sum[1]+j-(i-j)))%=MOD;
	}
	for(auto &p:ansl) {
		ll c=p.first;
		ll &ans=p.second; ans=0;
		fr(i,0,m) (ans+=dp[m][i]*c%MOD*(sum[1]+i)%MOD*inv(sum[1]))%=MOD;
	}
	//like
	fr(i,1,n) printf("%lld\n",((a[i]?ansl[w[i]]:ansd[w[i]])+MOD)%MOD);
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