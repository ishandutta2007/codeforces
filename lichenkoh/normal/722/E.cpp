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
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n) { ll ret = 1; ll p = a % MOD; while (n) { if (n & 1) ret = ret * p % MOD; p = p * p % MOD; n >>= 1; } return ret; }

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
typedef pair<ll,ll> pll;
typedef pair<ll,pll> ppll;
vector<ppll> p;
ll n,m,k,s;
const ll mn=2004;
const ll mc=22;
ll f[mn][mc+2];
inline ll mul(ll x,ll y) {return (x*y)%MOD;}
inline ll add(ll x,ll y) {return (x+y+MOD+MOD)%MOD;}
const ll MAXFACT=2e5+4;
ll fact[MAXFACT+1],invfact[MAXFACT+1];
void init() {
	ll got=1;
	for (ll x=0;x<=MAXFACT;x++) {
		fact[x]=got;
		got=mul(got,x+1);
	}
	got=mod_pow(got,MOD-2);
	for (ll x=MAXFACT;x>=0;x--) {
		got=mul(got,x+1);
		invfact[x]=got;
	}
}
ll binom(ll n,ll k) {
	if (n<k) return 0;
	if (n<0||k<0) return 0;
	return mul(fact[n],mul(invfact[k],invfact[n-k]));
}

inline ll ways(ll a, ll b) {
	ll ax=p[a].second.first,ay=p[a].second.second;
	ll bx=p[b].second.first,by=p[b].second.second;
	ll dx=bx-ax,dy=by-ay;
	if (dx<0||dy<0) return 0;
	return binom(dx+dy,dx);
}
int main()
{
	init();
	ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%lld %lld %lld %lld",&n,&m,&k,&s);
	bool has=false;
	bool hasz=false;
	for (ll i=0;i<k;i++) {
		ll r,c; scanf("%lld %lld",&r,&c);
		p.PB(MP(r+c,MP(r,c)));
		if (r==n&&c==m) has=true;
		if (r==1&&c==1) hasz=true;
	}
	if (!has) p.PB(MP(n+m,MP(n,m)));
	if (!hasz) p.PB(MP(1+1,MP(1,1)));
	sort(p.begin(),p.end());
	k=p.size();
	memset(f,0,sizeof f);
	//f[0][1]=1;
	for (ll b=0;b<k;b++) {
		f[b][0]=ways(0,b);
	}
	for (ll b=1;b<k;b++) {
		for (ll c=1;c<mc;c++) {
			ll sum=0;
			for (ll a=0;a<b;a++) {
				ll v1=f[a][c-1];
				ll v2=f[a][c];
				ll v=add(v1,-v2);
				ll toadd=mul(v,ways(a,b));
				//if(toadd)printf("(%lld,%lld)v1:%lld-%lld=%lld (%lld,%lld)v2:%lld v:%lld ways:%lld toadd:%lld\n",
				//	a,c-1,f[a][c-1],f[a][c],v1,a,c,v2,v,ways(a,b),toadd);
				sum=add(sum,toadd);
			}
			//if (c<5)printf("b:%lld c:%lld sum:%lld\n",b,c,sum);
			f[b][c]=sum;
		}
	}
	if (!has) s*=2;
	if (!hasz) s*=2;
	ll final=0;
	//for (ll c=1;c<5;c++) {
	//	printf("c:%lld num:%lld\n",c,f[k-1][c]);
	//}
	s=(s+1)/2;s=(s+1)/2;
	for (ll c=1;c<mc;c++) {
		ll num=add(f[k-1][c],-f[k-1][c+1]);
		ll plus=mul(num,s);
		//if (plus)printf("c:%lld num:%lld s:%lld p:%lld\n",c,num,s,plus);
		final=add(final,plus);
		s=(s+1)/2;
	}
	//printf("%lld\n",final);
	final=mul(final,mod_inv(ways(0,k-1),MOD));
	printf("%lld\n",final);
}