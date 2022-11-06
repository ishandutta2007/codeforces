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
ll a1[mn],b1[mn],a2[mn],b2[mn];
typedef pair<ll,pll> ppll;
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; scanf("%lld",&n);
	for (ll i=1;i<=n;i++) {
		scanf("%lld%lld%lld%lld",a1+i,b1+i,a2+i,b2+i);
	}
	ll a=0,b=0;
	priority_queue<pll> pq; // Max heap
	for (ll i=1;i<=n;i++) {
		if (a1[i]+b1[i]<=a2[i]+b2[i]) {
			if (a1[i]>b2[i]) {
				// Alice takes top
				a+=a1[i];
				b+=b2[i];
			}
			if (b1[i]>a2[i]) {
				// Bob takes top
				b+=b1[i];
				a+=a2[i];
			}
		}
		else {
			pq.push(MP(a1[i]+b1[i],i));
		}
	}
	ll turn=0;
	while(!pq.empty()) {
		pll top=pq.top(); pq.pop();
		ll i=top.second;
		if (i>0) pq.push(MP(a2[i]+b2[i],-i));
		ll l,r;
		if (i>0) l=a1[i],r=b1[i];
		else l=a2[abs(i)],r=b2[abs(i)];
		//printf("turn:%lld l:%lld r:%lld\n",turn,l,r);
		if (turn) b+=r;
		else a+=l;
		turn^=1;
	}
	printf("%lld\n",a-b);
}