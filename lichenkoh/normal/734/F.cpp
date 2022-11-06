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
const ll mn=2e5+4;
ll b[mn],c[mn],a[mn];
ll p[mn],q[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; scanf("%lld",&n);
	for (ll i=0;i<n;i++) scanf("%lld",b+i);
	for (ll i=0;i<n;i++) scanf("%lld",c+i);
	if (n==1) {
		a[0]=b[0];
	}
	else {
		ll s=0;
		for (ll i=0;i<n;i++) s+=b[i]+c[i];
		//printf("s:%lld\n",s);
		s/=(2*n);
		//printf("s:%lld\n",s);
		for (ll i=0;i<n;i++) a[i]=(b[i]+c[i]-s)/(n);
	}
	//for (ll i=0;i<n;i++) printf("%lld ",a[i]);
	memset(p,0,sizeof p);memset(q,0,sizeof q);
	for (ll k=0;k<31;k++) {
		ll t[2]; t[0]=0;t[1]=0;
		for (ll i=0;i<n;i++) {
			t[1&(a[i]>>k)]++;
		}
		for (ll i=0;i<n;i++) {
			ll self=1&(a[i]>>k);
			if (self==1) {
				p[i]+=(1ll<<k)*t[1];
				q[i]+=(1ll<<k)*n;
			}
			else {
				q[i]+=(1ll<<k)*t[1];
			}
		}
	}
	for (ll i=0;i<n;i++) {
		if (p[i]!=b[i]||q[i]!=c[i]) {
			printf("-1\n"); return 0;
		}
	}
	for (ll i=0;i<n;i++) printf("%lld ",a[i]);
	printf("\n");
}