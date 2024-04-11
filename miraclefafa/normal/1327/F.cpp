#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=501000;
int n,k,m,cnt[N],ss[N];
ll dp[N],ans=1;
VI l[N];
ll solve(vector<PII> f,vector<int> g) {
	int m=SZ(g);
	rep(i,1,n+1) ss[i]=0;
	for (auto x:g) ss[x]++;
	rep(i,1,n+1) ss[i]+=ss[i-1];
	rep(i,0,SZ(f)) {
		f[i].fi=ss[f[i].fi-1]+1;
		f[i].se=ss[f[i].se];
		if (f[i].fi>f[i].se) return 0;
	}
	rep(i,0,m+1) l[i].clear();	
	for (auto x:f) l[x.se].pb(x.fi);
	ll sdp=1;
	dp[0]=1;
	int posl=0;
	rep(i,1,m+1) {
		dp[i]=sdp; sdp=sdp*2%mod;
		int pr=posl;
		for (auto x:l[i]) posl=max(posl,x);
		rep(j,pr,posl) {
			sdp=(sdp-dp[j])%mod;
			dp[j]=0;
		}
		//rep(j,0,m+1) printf("%lld ",dp[j]); puts("");
	}
	if (sdp<0) sdp+=mod;
	return sdp;
}

int pl[N],pr[N],x[N];
int main() {
	scanf("%d%d%d",&n,&k,&m);;
	rep(i,0,m) scanf("%d%d%d",pl+i,pr+i,x+i);
	rep(j,0,k) {
		vector<int> g;
		vector<PII> cs;
		rep(i,1,n+1) cnt[i]=0;
		rep(i,0,m) {
			if (x[i]&(1<<j)) {
				cnt[pl[i]]++; cnt[pr[i]+1]--;
			} else cs.pb(mp(pl[i],pr[i]));
		}
		rep(i,1,n+1) cnt[i]+=cnt[i-1];
		rep(i,1,n+1) if (cnt[i]==0) g.pb(i);
		ans=ans*solve(cs,g)%mod;
	}
	printf("%lld\n",ans);
}