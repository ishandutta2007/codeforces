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
bool busy[104];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,q; scanf("%lld%lld",&n,&q);
	memset(busy,0,sizeof busy);
	priority_queue<pll,vector<pll>,greater<pll> > pq;
	for (ll jj=0;jj<q;jj++) {
		ll t,k,d;
		scanf("%lld%lld%lld",&t,&k,&d);
		while(!pq.empty()) {
			auto got=pq.top();
			ll s=got.first,id=got.second;
			//printf("t:%lld s:%lld id:%lld\n",t,s,id);
			if (s>t) break;
			pq.pop();
			busy[id]=false;
		}
		//for (ll x=0;x<n;x++) {
		//	printf("%d ",busy[x]);
		//}
		//printf("\n");
		vector<ll> vid;
		ll id=0;
		for (ll x=0;x<k;x++) {
			while(id<n&&busy[id]) id++;
			if (id<n) {
				vid.PB(id);
				id++;
			}
		}
		if (vid.size()==k) {
			ll sum=0;
			for (auto &x:vid) {
				busy[x]=true;
				pq.push(MP(t+d,x));
				sum+=(x+1);
			}
			printf("%lld\n",sum);
		}
		else {
			printf("-1\n");
		}
	}
}