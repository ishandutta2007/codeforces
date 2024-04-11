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
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=401000;
int n,a[N],bar[N],rk[N],smx[N];
ll dp[N],dp2[N],dp3[N];

struct fenwick {
	int n;
	ll c[N];
	void init(int nn) {
		n=nn;
		rep(i,1,n+1) c[i]=0;
	}
	int query(int x) {
		int s=0;
		for (;x;x-=x&-x) s=(s+c[x])%mod;
		return s;
	}
	void modify(int x,int s) {
		for (;x<=n;x+=x&-x) c[x]=(c[x]+s)%mod;
	}
}c0,c1;

void solve() {
	scanf("%d",&n);
	vector<PII> num;
	rep(i,1,n+1) {
		scanf("%d",a+i);
		num.pb({a[i],-i});
	}
	sort(all(num));
	rep(i,0,n) a[-num[i].se]=i+1;
	c0.init(n);
	c1.init(n);
	int mx=0;
	per(i,1,n+1) {
		rk[a[i]]=i;
		if (a[i]>mx) smx[i]=1,mx=a[i];
		else smx[i]=0;
	}
	ll ans=0;
	rep(i,1,n+1) {
		int x=a[i];
		dp[i]=(1+c0.query(x-1))%mod;
		c0.modify(x,dp[i]);
		dp2[i]=(c1.query(x-1)+dp[i])%mod;
		c1.modify(x,dp2[i]);
		if (!smx[i]) ans=(ans+dp2[i])%mod;
	}
	c0.init(n);
	VI md;
	per(i,1,n+1) {
		int pos=rk[i];
		if (smx[pos]) {
			for (auto x:md) {
				c0.modify(n+1-x,mod-dp3[x]);
				bar[x]=i;
			}
			md.clear();
			dp3[pos]=1;
			c0.modify(n+1-pos,dp3[pos]);
			md.pb(pos);
		} else {
			dp3[pos]=(c0.query(n+1-pos))%mod;
			c0.modify(n+1-pos,dp3[pos]);
			md.pb(pos);
		}
	}
	for (auto x:md) bar[x]=0;
	c1.init(n);
	rep(i,1,n+1) {
		ans=(ans+dp3[i]*c1.query(bar[i]))%mod;
		c1.modify(a[i],dp2[i]);
	}
	printf("%lld\n",ans);
}

int _;
int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}