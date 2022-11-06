#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;

template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) {
	if (n<0) return mod_inv(mod_pow(a,-n,mod),mod);
	ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret;
}

ll getSqrtModP(ll n, ll p) {
	n%=p;
	//printf("n:%lld p:%lld\n",n,p);
	/* Tonelli-Shanks algorithm */
	// Returns -1 if no root.
	// Returns a solution x. p-x is the second root UNLESS x=0
	if (p==2) { // Tonelli-Shanks only works on odd primes
		for (ll x=0;x<p;x++) {
			if ((x*x)%p==n) return x;
		}
		return -1;
	}
	if (n==0) return 0;
	ll legendre=mod_pow(n,(p-1)/2,p);
	if (legendre!=1) {
		assert(legendre==p-1);
		return -1;
	}
	ll S=0;
	ll Q=p-1;
	while(Q%2==0) {
		Q/=2; S++;
	}
	if (S==1) {
		return mod_pow(n,(p+1)/4,p);
	}
	// There at exactly (p-1)/2 quadratic residues mod p
	// So hopefully we hit a nonresidue fast enough :)
	ll z;
	srand(clock()&0xffff);
	while(1) {
		z=rand()%p;
		if (mod_pow(z,(p-1)/2,p)==p-1) break;
	}
	//z=2; assert(p==13);
	ll c=mod_pow(z,Q,p);
	ll R=mod_pow(n,(Q+1)/2,p);
	ll t=mod_pow(n,Q,p);
	ll M=S;
	//printf("c:%d R:%d t:%d M:%d\n",c,R,t,M);
	while(1) {
		if (t==1) {
			assert((R*R)%p==n);
			return R;
		}
		ll tTo2i=(t*t)%p;
		ll i=1;
		for (;i<M;i++) {
			if (tTo2i==1) break;
			tTo2i=(tTo2i*tTo2i)%p;
		}
		ll b=c;
		for (ll j=0;j<(M-i-1);j++) {
			b=(b*b)%p;
		}
		R=(R*b)%p;
		c=(b*b)%p;
		t=(t*c)%p;
		M=i;
	}
}

const ll mn=1e5+4;
ll a[mn];
ll n;
ll p;
bool check(ll x, ll d) {
	set<ll> s; for (ll i=0;i<n;i++) s.insert(a[i]);
	ll y=x;
	for (ll i=0;i<n;i++) {
		auto it=s.find(y);
		if (it==s.end()) return false;
		s.erase(it);
		y=(y+d)%p;
	}
	return true;
}
ll norm(ll x) {
	x%=p;
	if (x<0) x+=p;
	return x;
}
ll mul(ll x,ll y) {
	return norm(x*y);
}
int main() {
	//p=17;
	////printf("%lld\n",mul(2,getSqrtModP(3*mod_inv(5LL,p),p)));
	//return 0;
	//ll ans=getSqrtModP(10,13);
	//printf("ans:%lld\n",ans);
	//return 0;
	scanf("%lld%lld",&p,&n);
	for (ll i=0;i<n;i++) scanf("%lld",&a[i]);
	bool same=true;
	for (ll i=1;i<n;i++) {
		if (a[i]!=a[i-1]) {same=false; break;}
	}
	if (same||n==1) {printf("%lld 0\n",a[0]); return 0;}
	if (check(a[0],1)) {
		printf("%lld 1\n",a[0]); return 0;
	}
	ll e=0;
	for (ll i=0;i<n;i++) {
		e+=a[i]; e%=p;
	}
	ll f=0;
	for (ll i=0;i<n;i++) {
		f+=mul(a[i],a[i]); f%=p;
	}
	ll g=e;
	//x = (
	// -sqrt(-4 e^2 g n + e^2 h^2 + 4 f g n^2 - 4 f h n + 4 f n)
	// + 2 e g n - e h)/(2 n (g n - h + 1)) 
	ll n2=mul(n,n),g2=mul(g,g);
	ll discriminant=norm(3*norm(mul(n2,mul(n2-1,mul(f,n)-g2))));
	ll sqrtDis=getSqrtModP(discriminant,p);
	//printf("d:%lld sqrt:%lld p:%lld\n",discriminant,sqrtDis,p);
	if (sqrtDis==-1) {printf("-1\n"); return 0;}
	ll x=norm(-sqrtDis+mul(g,mul(n,n+1)))*mod_inv(mul(n2,n+1),p);
	x=norm(x);
	ll d=mul(norm(e-n*x),mod_inv((n*(n-1))/2,p));
	if (check(x,d)) printf("%lld %lld\n",x,d);
	else printf("-1\n");
	/*
	ll e=0;
	for (ll i=0;i<n;i++) e=(e+a[i])%p;
	ll f=0;
	for (ll i=0;i<n;i++) e=(e+a[i]*a[i])%p;
	ld gnum=((n-1)*n*(2*n-1))/6;
	ld gden=(n*(n-1))/2; gden=gden*gden;
	ld g=gnum/gden;
	ld discriminant=e*e*(-g) - 2*e + f*g*n*n + f + n*n;
	if (discriminant<=0) discriminant=max(discriminant,1e-18);
	discriminant=sqrt(discriminant);
	ld x1=(-discriminant+e*g*n+n)/(g*n*n+1);
	ld x2=(-discriminant+e*g*n+n)/(g*n*n+1);
	for (ll x=x1-2;x<=x1+2;x++) {
		ld dd=(e-n*x)/((n*(n-1))/2);
		for (ll d=dd-2;d<=dd+2;d++) {
			if (check(x,d)) {
				printf("%lld %lld\n",x,d);
				return 0;
			}
		}
	}
	for (ll x=x2-2;x<=x2+2;x++) {
		ld dd=(e-n*x)/((n*(n-1))/2);
		for (ll d=dd-2;d<=dd+2;d++) {
			if (check(x,d)) {
				printf("%lld %lld\n",x,d);
				return 0;
			}
		}
	}
	printf("-1\n");*/
}