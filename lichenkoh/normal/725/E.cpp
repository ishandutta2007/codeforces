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
ll v[mn];
vector<ll> b;
ll getidx(ll x, ll upper) {
	ll imin=0,imax=upper;
	while(imin<imax) {
		ll imid=(imin+imax)/2;
		if (b[imid]<=x) imin=imid+1;
		else imax=imid;
		//printf("x:%lld imin:%lld imax:%lld\n",x,imin,imax);
	}
	if (imin<upper&&b[imin]<=x) return imin;
	imin--;
	if (0<=imin&&imin<upper&&b[imin]<=x) return imin;
	return -1;
}
ll h[mn];
int main()
{
	ll c,n; scanf("%lld%lld",&c,&n);
	for (ll i=0;i<n;i++) {
		scanf("%lld",&v[i]);
	}
	set<ll> s;
	for (ll i=0;i<n;i++) s.insert(v[i]);
	for (auto &w:s) {b.PB(w);}
	ll bsz=b.size();
	memset(h,0,sizeof h);
	for (ll i=0;i<n;i++) {
		ll idx=getidx(v[i],bsz);
		h[idx]++;
	}
	for (ll ans=1;ans<200000;ans++) {
		ll live=c;
		//printf("live:%lldc:%lld\n",live,c);
		ll upper=bsz;
		bool avail=true;
		while(1) {
			ll idx=getidx(live,upper);
			//printf("%lld %lld got %lld\n",live,upper,idx);
			ll coin=(idx==-1)?-1:b[idx];
			if (avail&&ans>=coin&&ans<=live) {
				avail=false;
				live-=ans;
				//printf("Take ans:%lld\n",ans);
			}
			else if (coin!=-1){
				ll take=min(live/coin,h[idx]);
				//printf("Take:%lld coin:%lld\n",take,coin);
				live-=take*coin;
				upper=idx;
			}
			if (coin==-1||live==0) break;
		}
		if (live!=0) {
			printf("%lld\n",ans);
			return 0;
		}
	}
	printf("Greed is good\n");
	
}