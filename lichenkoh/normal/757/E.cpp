#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
#define all(x) x.begin(),x.end()
const ll UNDEF = -1;
const ll INF=1e18;
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
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
const ll MAXN=1e6+4;
const ll MAXP=MAXN;
bool sieve_array[MAXP+1];
ll sp[MAXP+1];
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
			chkmin(sp[i],i);
		}
	}
}
map<ll,ll> factorize(ll x) {
	map<ll,ll> h;
	while(x>1) {
	ll p=sp[x];
	x/=p;
	h[p]++;
	}
	if (x>1) h[x]++;
	return h;
}
const ll mn=1e6+2,me=21;
ll f[mn][me];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	f[0][0]=1;
	for (ll e=1;e<me;e++) f[0][e]=2;
	for (ll n=1;n<mn;n++) {
		ll sum=0;
		for (ll e=0;e<me;e++) {
			sum=(sum+f[n-1][e])%MOD;
			f[n][e]=sum;
		}
	}
	sieve();
	ll q; scanf("%lld",&q);
	for (ll ii=0;ii<q;ii++) {
		ll n,r; scanf("%lld%lld",&r,&n);
		map<ll,ll> h=factorize(n);
		ll ans=1;
		for (auto &w:h) {
			//printf("n:%lld w.snd:%lld\n",n,w.snd);
			ans=(ans*f[r][w.snd])%MOD;
		}
		printf("%lld\n",ans);
	}
}