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
inline ll mul(ll x,ll y) {
	x%=MOD; y%=MOD;
	if (x<0) x+=MOD;
	if (y<0) y+=MOD;
	return (x*y)%MOD;
}
inline ll add(ll x,ll y) {
	x%=MOD; y%=MOD;
	if (x<0) x+=MOD;
	if (y<0) y+=MOD;
	return (x+y)%MOD;
}
const ll inv2=500000004;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,maxm; scanf("%lld %lld",&n,&maxm);
	ll slim=sqrt(n);
	ll final=0;
	for (ll m=1;m<=min(maxm,slim);m++) {
		final+=(n%m);
		final%=MOD;
	}
	for (ll k=1;k<=slim;k++) {
		ll a=(n+1+k)/(k+1);
		ll b=(n-1)/k;
		//printf("k:%d a:%d b:%d\n",k,a,b);
		a=max(a,slim+1);
		b=min(b,maxm);
		//printf("k:%d a:%d b:%d\n",k,a,b);
		if (a>b) continue;
		ll arith=mul(mul((b-a+1),(b+a)),inv2);
		ll sum=add(mul(b-a+1,n),-mul(k,arith));
		final+=sum;
		final%=MOD;
		//printf("Add:%lld\n",sum);
	}
	if (maxm>n) {
		final+=mul(add(maxm,-n),n);
		//printf("Woof:%lld %lld %lld\n",(maxm-n)*n,maxm,n);
	}
	final%=MOD;
	printf("%lld\n",final);
}