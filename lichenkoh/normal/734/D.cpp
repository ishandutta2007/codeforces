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
const ll mn=5e5+4;
pair<ll,char> a[4];
pair<ll,char> b[4];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,xi,yi;
	scanf("%lld\n",&n);
	scanf("%lld %lld\n",&xi,&yi);
	for (ll s=0;s<4;s++) a[s]=MP(INF,'X');
	for (ll s=0;s<4;s++) b[s]=MP(INF,'X');
	for (ll i=0;i<n;i++) {
		ll x,y; char c;
		scanf("%c %lld %lld\n",&c,&x,&y);
		ll dx=x-xi,dy=y-yi;
		if (dx==0) {
			if (dy>0) chkmin(a[0],MP(abs(dy),c));
			else chkmin(a[1],MP(abs(dy),c));
		}
		else if (dy==0) {
			if (dx>0) chkmin(a[2],MP(abs(dx),c));
			else chkmin(a[3],MP(abs(dx),c));
		}
		else if (abs(dx)==abs(dy)) {
			ll sign=0;
			if (dx>0) sign|=1;
			if (dy>0) sign|=2;
			chkmin(b[sign],MP(abs(dx),c));
		}
	}
	bool ans=false;
	for (ll s=0;s<4;s++) {
		char c=a[s].second;
		if (c=='Q'||c=='R') ans=true;
	}
	for (ll s=0;s<4;s++) {
		char c=b[s].second;
		if (c=='Q'||c=='B') ans=true;
	}
	if (ans) printf("YES\n");
	else printf("NO\n");
}