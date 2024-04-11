#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

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

const int MOD=1000000007; 
using mi = mint<MOD,5>; // 5 is primitive root for both common mods

namespace simp {
	vector<mi> fac,ifac,invn;
	void check(int x) {
		if (fac.empty()) {
			fac={mi(1),mi(1)};
			ifac={mi(1),mi(1)};
			invn={mi(0),mi(1)};
		}
		while (SZ(fac)<=x) {
			int n=SZ(fac),m=SZ(fac)*2;
			fac.resize(m);
			ifac.resize(m);
			invn.resize(m);
			for (int i=n;i<m;i++) {
				fac[i]=fac[i-1]*mi(i);
				invn[i]=mi(MOD-MOD/i)*invn[MOD%i];
				ifac[i]=ifac[i-1]*invn[i];
			}
		}
	}
	mi gfac(int x) {
		check(x); return fac[x];
	}
	mi ginv(int x) {
		check(x); return invn[x];
	}
	mi gifac(int x) {
		check(x); return ifac[x];
	}
	mi binom(int n,int m) {
		if (m < 0 || m > n) return mi(0);
		return gfac(n)*gifac(m)*gifac(n - m);
	}
}

const int N=1010000;
mi inv2=mi(1)/mi(2);
mi dp[N],pd[N],pw[N],ipw[N],sdp[N],spd[N];
int n;

void solve() {
	scanf("%d",&n);
	dp[1]=mi(1);
	for (int i=2;i<=n;i++) {
		dp[i]=pow(inv2,(i+1)/2-(i==n));

	}
	pd[n]=mi(1);
	for (int i=n-1;i>=1;i--) {
		pd[i]=mi(0);
		for (int j=i+1;j<=n;j++) if (j-i<i) {
			pd[i]+=pow(inv2,j-(j==n)-i)*pd[j];
		}
	}
	for (int i=1;i<=n;i++) {
		mi ans=dp[i]*pd[i];
		printf("%d\n",(int)ans);
	}
}

void solve2() {
	scanf("%d",&n);
	pw[0]=ipw[0]=mi(1);
	for (int i=1;i<=n;i++) {
		pw[i]=pw[i-1]*mi(2);
		ipw[i]=ipw[i-1]*inv2;
	}
	dp[1]=mi(1);
	for (int i=2;i<=n;i++) {
		dp[i]=pow(inv2,(i+1)/2-(i==n));
	}

	pd[n]=mi(1);
	spd[n+1]=mi(0);
	spd[n]=pd[n]*ipw[n-1];
	for (int i=n-1;i>=1;i--) {
		pd[i]=spd[i+1]-spd[min(n,i+i-1)+1];
		pd[i]=pd[i]*pw[i];
		spd[i]=spd[i+1]+pd[i]*ipw[i];
	}
	for (int i=1;i<=n;i++) {
		mi ans=dp[i]*pd[i];
		printf("%d\n",(int)ans);
	}
}

int _;

int main() {
	for (scanf("%d",&_);_;_--) {
		//solve();
		solve2();
	}
}