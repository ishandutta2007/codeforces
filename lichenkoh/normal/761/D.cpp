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
const ll mn=1e5+4;
ll a[mn],c[mn],b[mn];
pll p[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,l,r; scanf("%lld%lld%lld",&n,&l,&r);
	for (ll i=0;i<n;i++) scanf("%lld",a+i);
	for (ll i=0;i<n;i++) scanf("%lld",c+i);
	for (ll i=0;i<n;i++) {
		p[i]=MP(c[i],i);
	}
	sort(p,p+n);
	ll lo=-INF;
	for (ll j=0;j<n;j++) {
		ll i=p[j].second;
		ll gotc=max(lo+1,l-a[i]);
		ll gotb=gotc+a[i];
		if (!(l<=gotb&&gotb<=r)) {
			printf("-1\n");
			return 0;
		}
		b[i]=gotb;
		lo=gotc;
	}
	for (ll i=0;i<n;i++) {
		printf("%lld ",b[i]);
	}
	printf("\n");
}