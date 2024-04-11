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
const ll mod=998244353;
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

const int MOD=998244353; 
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

mi s[2010][2010];
int _;
int main() {
	s[0][0]=1;
	for (int i=1;i<=2000;i++) {
		for (int j=1;j<=i;j++)
			s[i][j]=s[i-1][j-1]+j*s[i-1][j];
	}
	for (scanf("%d",&_);_;_--) {
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		int odd=(m+1)/2;
		mi invm=mi(1)/mi(m);
		mi v=pow(mi(m),n),ans=0;
		for (int j=0;j<=k;j++) {
			ans=ans+v*s[k][j];
			v=v*(n-j)*odd*invm;
		}
		printf("%d\n",(int)ans);
	}
}