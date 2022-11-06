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
const ll mn=504;
ll a[mn],b[mn];
vector<pair<ll,char> > vans;
bool process(vector<ll> v, ll off) {
	ll n=v.size();
	ll binit=-1;
	//for (auto &w:v) printf("%lld ",w);
	//printf(" off:%lld\n",off);
	for (ll init=0;init<n;init++) {
		ll cur=v[init];
		bool good=true;
		ll l=init-1,r=init+1;
		while(l>=0||r<n) {
			//printf("init:%lld cur:%lld l:%lld r:%lld\n",init,cur,l,r);
			if (l>=0&&cur>v[l]) {cur+=v[l];l--;}
			else if (r<n&&cur>v[r]) {cur+=v[r];r++;}
			else {
				//printf("init:%lld cur:%lld l:%lld r:%lld BAD\n",init,cur,l,r);
				good=false;
				break;
			}
		}
		if(good) {binit=init; break;}
	}
	if (binit==-1) return false;
	{
		ll init=binit;
		ll cur=v[init];
		bool good=true;
		ll l=init-1,r=init+1;
		while(l>=0||r<n) {
			if (l>=0&&cur>v[l]) {
				vans.PB(MP(l+1+off,'L'));
				cur+=v[l];l--;
			}
			else if (r<n&&cur>v[r]) {
				vans.PB(MP(l+1+off,'R'));
				cur+=v[r];r++;
			}
			else assert(false);
		}
		return true;
	}
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,k; scanf("%lld",&n);
	for (ll i=0;i<n;i++) scanf("%lld",&a[i]);
	scanf("%lld",&k);
	for (ll i=0;i<k;i++) scanf("%lld",&b[i]);
	bool ok=true;
	{
		ll x=n-1;
		for (ll y=k-1;y>=0;y--) {
			ll sum=0;
			ll sx=x;
			while(x>=0&&sum<b[y]) {
				sum+=a[x]; x--;
			}
			ll ex=x+1;
			//printf("y:%lld ex:%lld sx:%lld sum:%lld\n",y,ex,sx,sum);
			if (sum!=b[y]) {ok=false; break;}
			
			vector<ll> v;
			for (ll x=ex;x<=sx;x++) {
				v.PB(a[x]);
			}
			if(!process(v,ex+1)) ok=false;
		}
		if (x!=-1) ok=false;
	}
	if (!ok) {
		printf("NO\n");
	}
	else {
		printf("YES\n");
		for (auto &w:vans) {
			printf("%lld %c\n",w.first,w.second);
		}
	}
}