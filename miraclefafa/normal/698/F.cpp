#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
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
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

/*int n,p[1010];
map<VI,int> hs;
VI v;
bool check() {
	rep(p1,1,n+1) rep(p2,p1+1,n+1) if ((__gcd(p1,p2)==1)!=(__gcd(p[p1],p[p2])==1)) {
		return 0;
	}
	return 1;
}*/

typedef pair<ll,ll> PLL;
namespace Factor {
	const int N=1010000;
	ll C,fac[10010],n,mut,a[1001000];
	int T,cnt,i,l,prime[N],p[N],psize,_cnt;
	ll _e[100],_pr[100];
	vector<ll> d;
	inline ll mul(ll a,ll b,ll p) {
		if (p<=1000000000) return a*b%p;
		else if (p<=1000000000000ll) return (((a*(b>>20)%p)<<20)+(a*(b&((1<<20)-1))))%p;
		else {
			ll d=(ll)floor(a*(long double)b/p+0.5);
			ll ret=(a*b-d*p)%p;
			if (ret<0) ret+=p;
			return ret;
		}
	}
	void prime_table(){
		int i,j,tot,t1;
		for (i=1;i<=psize;i++) p[i]=i;
		for (i=2,tot=0;i<=psize;i++){
			if (p[i]==i) prime[++tot]=i;
			for (j=1;j<=tot && (t1=prime[j]*i)<=psize;j++){
				p[t1]=prime[j];
				if (i%prime[j]==0) break;
			}
		}
	}
	void init(int ps) {
		psize=ps;
		prime_table();
	}
	ll powl(ll a,ll n,ll p) {
		ll ans=1;
		for (;n;n>>=1) {
			if (n&1) ans=mul(ans,a,p);
			a=mul(a,a,p);
		}
		return ans;
	}
	bool witness(ll a,ll n) {
		int t=0;
		ll u=n-1;
		for (;~u&1;u>>=1) t++;
		ll x=powl(a,u,n),_x=0;
		for (;t;t--) {
			_x=mul(x,x,n);
			if (_x==1 && x!=1 && x!=n-1) return 1;
			x=_x;
		}
		return _x!=1;
	}
	bool miller(ll n) {
		if (n<2) return 0;
		if (n<=psize) return p[n]==n;
		if (~n&1) return 0;
		for (int j=0;j<=7;j++) if (witness(rand()%(n-1)+1,n)) return 0;
		return 1;
	}
	ll gcd(ll a,ll b) {
		ll ret=1;
		while (a!=0) {
			if ((~a&1) && (~b&1)) ret<<=1,a>>=1,b>>=1;
			else if (~a&1) a>>=1; else if (~b&1) b>>=1;
			else {
				if (a<b) swap(a,b);
				a-=b;
			}
		}
		return ret*b;
	}
	ll rho(ll n) {
		for (;;) {
			ll X=rand()%n,Y,Z,T=1,*lY=a,*lX=lY;
			int tmp=20;
			C=rand()%10+3;
			X=mul(X,X,n)+C;*(lY++)=X;lX++;
			Y=mul(X,X,n)+C;*(lY++)=Y;
			for(;X!=Y;) {
				ll t=X-Y+n;
				Z=mul(T,t,n);
				if(Z==0) return gcd(T,n);
				tmp--;
				if (tmp==0) {
					tmp=20;
					Z=gcd(Z,n);
					if (Z!=1 && Z!=n) return Z;
				}
				T=Z;
				Y=*(lY++)=mul(Y,Y,n)+C;
				Y=*(lY++)=mul(Y,Y,n)+C;
				X=*(lX++);
			}
		}
	}
	void _factor(ll n) {
		for (int i=0;i<cnt;i++) {
			if (n%fac[i]==0) n/=fac[i],fac[cnt++]=fac[i];}
		if (n<=psize) {
			for (;n!=1;n/=p[n]) fac[cnt++]=p[n];
			return;
		}
		if (miller(n)) fac[cnt++]=n;
		else {
			ll x=rho(n);
			_factor(x);_factor(n/x);
		}
	}
	void dfs(ll x,int dep) {
		if (dep==_cnt) d.pb(x);
		else {
			dfs(x,dep+1);
			for (int i=1;i<=_e[dep];i++) dfs(x*=_pr[dep],dep+1);
		}
	}
	void norm() {
		sort(fac,fac+cnt);
		_cnt=0;
		rep(i,0,cnt) if (i==0||fac[i]!=fac[i-1]) _pr[_cnt]=fac[i],_e[_cnt++]=1;
			else _e[_cnt-1]++;
	}
	vector<ll> getd() {
		d.clear();
		dfs(1,0);
		return d;
	}
	vector<ll> factor(ll n) {
		cnt=0;
		_factor(n);
		norm();
		return getd();
	}
	vector<PLL> factorG(ll n) {
		cnt=0;
		_factor(n);
		norm();
		vector<PLL> d;
		rep(i,0,_cnt) d.pb(mp(_pr[i],_e[i]));
		return d;
	}
	bool is_primitive(ll a,ll p) {
		assert(miller(p));
		vector<PLL> D=factorG(p-1);
		rep(i,0,SZ(D)) if (powl(a,(p-1)/D[i].fi,p)==1) return 0;
		return 1;
	}
	ll simplify(ll n) {
		vector<PLL> d=factorG(n);
		ll c=1;
		for (auto p:d) c=c*p.fi;
		return c;
	}
}


const int N=1010000;
int n,v[N],simp[N],tr[N];
map<PII,int> hs;
map<int,int> h2;
PII big[N];

int main() {
	Factor::init(1000000);
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",v+i);
	rep(i,1,n+1) if ((ll)i*i>n&&Factor::miller(i)) {
		for (int j=i;j<=n;j+=i) big[j]=mp(i,j/i);
	}
	rep(i,1,n+1) simp[i]=Factor::simplify(i);
	big[1]=mp(1,1);
	rep(i,1,n+1) {
		if (big[i]==mp(0,0)) hs[mp(0,simp[i])]++;
		else {
			hs[mp(big[i].fi,simp[big[i].se])]++;
			if (big[i].se==1) {
				int c=n/i; if (i==1) c=1;
				h2[c]++;
			}
		}
	}
	rep(i,1,n+1) if (v[i]!=0) {
		// big prime
		if ((big[i]==mp(0,0))!=(big[v[i]]==mp(0,0))) {
			puts("0");
			return 0;
		}
		if (big[i]==mp(0,0)&&big[v[i]]==mp(0,0)) {
			if (simp[i]!=simp[v[i]]) { puts("0"); return 0; }
			hs[mp(0,simp[i])]--;
			// add case 0 i->v[i]
		} else {
			assert(big[i]!=mp(0,0)&&big[v[i]]!=mp(0,0));
			int p1=big[i].fi,p2=big[v[i]].fi;
			int c1=n/p1; if (p1==1) c1=1;
			int c2=n/p2; if (p2==1) c2=1;
			if (c1!=c2) { puts("0"); return 0; }
			if (tr[p1]!=0&&tr[p1]!=p2) { puts("0"); return 0; }
			if (tr[p1]==0) h2[c1]--,tr[p1]=p2;
			if (simp[big[i].se]!=simp[big[v[i]].se]) { puts("0"); return 0; }
			hs[mp(big[i].fi,simp[big[i].se])]--;
			// add case i i->v[i]
		}
	}
	// count
	ll way=1;
	for (auto p:hs) {
//		printf("%d %d %d\n",p.fi.fi,p.fi.se,p.se);
		rep(i,1,p.se+1) way=way*i%mod;
	}
	// prime converge
	for (auto p:h2) {
//		printf("%d %d\n",p.fi,p.se);
		rep(i,1,p.se+1) way=way*i%mod;		
	}
	printf("%lld\n",way);
}