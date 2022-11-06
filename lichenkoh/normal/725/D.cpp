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
const ll mn=3e5+4;
//typedef pair<ll,pll> ll;
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; scanf("%lld",&n);
	ll lt,lw;scanf("%lld%lld",&lt,&lw);
	priority_queue<pll> lesser; // Max heap
	priority_queue<ll,vector<ll>,greater<ll> > greater; // Min heap
	for (ll i=1;i<n;i++) {
		ll t,w;scanf("%lld%lld",&t,&w);
		if (t<=lt) lesser.push(MP(t,w));
		else greater.push(w-t+1);
	}
	ll final=INF;
	for (ll k=0;k<=n;k++) {
		ll gsz=greater.size();
		chkmin(final,gsz);
		//if (gsz==1) printf("k:%lld\n",k);
		if (gsz>0) {
			ll g=greater.top(); greater.pop();
			//assert(g.first>=0);
			lt-=g;
			if (lt<0) break;
			//printf("Float: %lld t:%lld w:%lld. lt is now:%lld\n",g.first,g.second.first,g.second.second,lt);
			while(!lesser.empty()) {
				pll x=lesser.top();
				ll xt=x.first,xw=x.second;
				if (x.first>lt) {
					lesser.pop();
					//printf("Transfer %lld %lld to greater\n",xt,xw);
					greater.push(xw-xt+1);
				}
				else break;
			}
		}
		else break;
	}
	final++;
	printf("%lld\n",final);
}