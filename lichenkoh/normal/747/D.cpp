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
ll a[mn];

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,k; scanf("%lld%lld",&n,&k);
	for (ll i=0;i<n;i++) scanf("%lld",a+i);
	ll past=-1;
	ll need=0;
	vector<ll> v;
	for (ll x=0;x<n;x++) {
		if (a[x]<0) {
			need++;
			if (past!=-1) {
				ll num=x-past-1;
				//printf("x:%lld past:%lld\n",x,past);
				v.PB(num);
			}
			past=x;
		}
	}
	ll left=k-need;
	if (need==0) {
		printf("0\n");
		return 0;
	}
	if (left<0) {
		printf("-1\n");
		return 0;
	}
	sort(v.begin(),v.end());
	ll sub=0;
	for (auto &w:v) {
		if (left>=w) {
			sub++;
			left-=w;
			//printf("w:%lld sub:%lld left:%lld\n",w,sub,left);
		}
	}
	ll ans=(need-sub)*2;
	if (n-past-1<=left) ans--;
	//printf("%lld %lld - 1 >= %lld\n",n,past,left);
	//printf("%lld %lld %lld %lld\n",need,sub,ans,left);
	printf("%lld\n",ans);
}