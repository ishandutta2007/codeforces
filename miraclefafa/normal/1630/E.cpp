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

const ll MOD=998244353;

template<int MOD, int RT> struct mint {
	static const int mod = MOD;
	static constexpr mint rt() { return RT; } // primitive root for FFT
	int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
	mint():v(0) {}
	mint(ll _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
		if (v < 0) v += MOD; }
	bool operator==(const mint& o) const {
		return v == o.v; }
	friend bool operator!=(const mint& a, const mint& b) { 
		return !(a == b); }
	friend bool operator<(const mint& a, const mint& b) { 
		return a.v < b.v; }
	//friend void re(mint& a) { ll x; re(x); a = mint(x); }
	//friend str ts(mint a) { return ts(a.v); }
   
	mint& operator+=(const mint& o) { 
		if ((v += o.v) >= MOD) v -= MOD; 
		return *this; }
	mint& operator-=(const mint& o) { 
		if ((v -= o.v) < 0) v += MOD; 
		return *this; }
	mint& operator*=(const mint& o) { 
		v = int((ll)v*o.v%MOD); return *this; }
	mint& operator/=(const mint& o) { return (*this) *= inv(o); }
	friend mint pow(mint a, ll p) {
		mint ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans; }
	friend mint inv(const mint& a) { assert(a.v != 0); 
		return pow(a,MOD-2); }
		
	mint operator-() const { return mint(-v); }
	mint& operator++() { return *this += 1; }
	mint& operator--() { return *this -= 1; }
	friend mint operator+(mint a, const mint& b) { return a += b; }
	friend mint operator-(mint a, const mint& b) { return a -= b; }
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	friend mint operator/(mint a, const mint& b) { return a /= b; }
};
 
using mi = mint<MOD,5>; // 5 is primitive root for both common mods

const int N=1010000;
mi pinv[N],fac[N],fnv[N];
int cnt[N],cc[N],a[N],n;
void solve() {
	scanf("%d",&n);
	rep(i,1,n+1) cnt[i]=0,cc[i]=0;
	rep(i,1,n+1) scanf("%d",a+i),cnt[a[i]]++;
	int dd=0;
	VI cp;
	rep(i,1,n+1) {
		dd=gcd(dd,cnt[i]);
		if (cnt[i]) cp.pb(cnt[i]);
	}
	if (SZ(cp)==1) {
		puts("1");
		return;
	}
	rep(d,1,n+1) cc[gcd(d,n)]++;
	mi perm(0),comp(0);
	rep(i,1,n+1) if (cc[n/i]!=0&&dd%i==0) {
		mi way=fac[n/i]*mi(cc[n/i]);
		for (auto p:cp) way*=fnv[p/i];
		//printf("%d %d\n",i,(int)way);
		ll tot=(ll)(n/i)*(n/i-1),sm=0;
		for (auto p:cp) sm+=(ll)(p/i)*((p/i)-1);
		mi ecomp=mi(n/i)*mi(tot-sm)/mi(tot)*i*way;
		comp+=ecomp; perm+=way;
		//printf("%d %d %d\n",i,(int)way,(int)ecomp);
	}
	//printf("%d\n",(int)(perm/n));
	printf("%d\n",(int)(comp/perm));
}
int _;
int main() {
	int M=1000000;
	fac[0]=fnv[0]=mi(1);
	for (int i=1;i<=M;i++) {
		if (i==1) pinv[i]=1;
		else pinv[i]=mi(MOD-MOD/i)*pinv[MOD%i];
		fac[i]=fac[i-1]*mi(i);
		fnv[i]=fnv[i-1]*pinv[i];
	}
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}