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
ll t[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; string a; cin>>n>>a;
	set<ll> sa,s[2];
	for (ll x=0;x<n;x++) t[x]=(a[x]=='D')?0:1;
	for (ll x=0;x<n;x++) {
		sa.insert(x);
		s[t[x]].insert(x);
	}
	auto cur=sa.begin();
	while(sa.size()>1) {
		ll x=*cur;
		ll q=t[x]^1;
		auto it=s[q].lower_bound(x);
		if (it==s[q].end()) {
			it=s[q].begin();
		}
		if (it!=s[q].end()) {
			ll y=*it;
			s[q].erase(y);
			sa.erase(y);
			//printf("x:%lld erases y:%lld\n",x,y);
		}
		if (s[0].empty()||s[1].empty()) break;
		cur=sa.upper_bound(x);
		if (cur==sa.end()) cur=sa.begin();
	}
	{
		ll q=t[*(sa.begin())];
		if (q==0) printf("D\n");
		else printf("R\n");
	}
}