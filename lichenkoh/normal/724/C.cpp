#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
const ll INF=5e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;

#ifdef DEBUG
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;

const ll MAXN=1e6+4;
const ll MAXP=MAXN;
bool sieve_array[MAXP+1];
ll sp[MAXP+1];
vector<ll> gpv;
void sieve() {
	for (ll i = 0; i <= MAXP; i++) {
		sieve_array[i] = true;
		sp[i]=INF;
	}
	sieve_array[0] = false; sieve_array[1] = false;
	ll lim = sqrt(MAXP)+1;
	for (ll i = 2; i <= lim; i++) {
		if(sieve_array[i]) {
			for (ll j = i*i; j <= MAXP; j+=i) {
				sieve_array[j] = false;
				chkmin(sp[j],i);
			}
		}
	}
	for (ll i = 2; i <= MAXP; i++) {
		if(sieve_array[i]) {
			gpv.PB(i);
			chkmin(sp[i],i);
		}
	}
}
map<ll,ll> factorize(ll x) {
	map<ll,ll> h;
	while(x>=MAXP) {
		bool found=false;
		for (auto &p:gpv) {
			if (p*p>x) break;
			if ((x%p)==0) {
				x/=p;
				h[p]++;
				found=true;
				break;
			}
		}
		if (!found) break;
	}
	if (x<MAXP) {
		while(x>1) {
		ll p=sp[x];
		x/=p;
		h[p]++;
		}
	}
	if (x>1) h[x]++;
	return h;
}

pair<ll,ll> extgcd(ll a, ll b) {
	ll s=0,old_s=1;
	ll t=1,old_t=0;
	ll r=b,old_r=a;
	while(r!=0) {
		ll q=old_r/r;
		ll tmp_r=r,tmp_s=s,tmp_t=t;
		r=old_r-q*r;
		s=old_s-q*s;
		t=old_t-q*t;
		old_r=tmp_r,old_s=tmp_s,old_t=tmp_t;
	}
	return MP(old_s,old_t);
}
inline ll mul(ll x,ll y,ll mod) {
	while(x<0) x+=mod;
	while(y<0) y+=mod;
	return (x*y)%mod;
}
inline ll norm(ll x, ll mod) {
	x%=mod;
	while(x<0) x+=mod;
	return x;
}
ll crt3(ll a1,ll n1,ll a2,ll n2) {
	pll bezout=extgcd(n1,n2);
	ll m1=bezout.first,m2=bezout.second;
	ll mod=(n1*n2);
	ll ans=(a1*m2*n2+a2*m1*n1)%mod;
	return norm(ans,mod);
}
ll crt2(vector<ll> &av, vector<ll> &nv) {
	ll vsz=av.size();
	ll ca=av[0];
	ll cn=nv[0];
	for (ll i=1;i<vsz;i++) {
		ca=crt3(ca,cn,av[i],nv[i]);
		cn*=nv[i];
	}
	return norm(ca,cn);
}
ll crt(ll a0,ll n0,ll a1,ll n1) {
	a0=norm(a0,n0); a1=norm(a1,n1);
	ll a[2]; a[0]=a0;a[1]=a1;
	map<ll,ll> factors[2];
	factors[0]=factorize(n0);
	factors[1]=factorize(n1);
	map<ll,pair<ll,ll> > v;
	for (ll i=0;i<2;i++) {
		for (auto &w:factors[i]) {
			ll p=w.first;
			ll mod=1;
			for (ll j=0;j<w.second;j++) mod*=p;
			chkmax(v[w.first],MP(mod,a[i]%mod));
		}
	}
	vector<ll> av,nv;
	for (auto &got:v) {
		pll w=got.second;
		nv.PB(w.first);
		av.PB(w.second);
	}
	ll ans=crt2(av,nv);
	if (ans%n0==a0&&ans%n1==a1) return ans;
	return INF;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieve();
	ll n,m,k; scanf("%lld%lld%lld",&n,&m,&k);
	for (ll i=0;i<k;i++) {
		ll px,py;scanf("%lld%lld",&px,&py);
		ll ans=INF;
		ll ax[2],ay[2];
		ax[0]=px;ax[1]=2*n-px;
		ay[0]=py;ay[1]=2*m-py;
		for (ll c=0;c<2;c++)for (ll d=0;d<2;d++) {
			ll t=crt(ax[c],2*n,ay[d],2*m);
			if (
				((t%(2*n))<n==(c==0))
				&&
				((t%(2*m)<m)==(d==0))
				) chkmin(ans,t);
		}
		if (ans>=INF) ans=-1;
		printf("%lld\n",ans);
	}
}