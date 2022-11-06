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
ll a[mn],b[mn],c[mn],d[mn];
pll v[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,m,k,x,s; scanf("%lld%lld%lld%lld%lld",&n,&m,&k,&x,&s);
	for (ll i=0;i<m;i++) scanf("%lld",a+i);
	for (ll i=0;i<m;i++) scanf("%lld",b+i);
	for (ll i=0;i<k;i++) scanf("%lld",c+i);
	for (ll i=0;i<k;i++) scanf("%lld",d+i);
	for (ll i=0;i<m;i++) {
		v[i]=MP(b[i],a[i]);
	}
	sort(v,v+m);
	for (ll i=0;i<m;i++) {
		b[i]=v[i].first;
		a[i]=v[i].second;
	}
	ll final=n*x;
	ll j=k-1;
	for (ll i=0;i<m;i++) {
		while(j>=0&&d[j]+b[i]>s) {
			j--;
		}
		if (j==-1) break;
		ll cand=a[i]*(n-c[j]);
		chkmin(final,cand);
	}
	for (ll i=0;i<m;i++) {
		if (b[i]<=s) {
			ll cand=a[i]*n;
			chkmin(final,cand);
		}
	}
	for (ll j=0;j<k;j++) {
		if (d[j]<=s) {
			ll cand=(n-c[j])*x;
			chkmin(final,cand);
		}
	}
	printf("%lld\n",final);
}