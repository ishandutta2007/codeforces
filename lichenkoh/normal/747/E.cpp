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
vector<ll> vans[mn];
vector<pair<string,ll> > v;
ll maxdepth=0;
ll dfs(ll x, ll depth) {
	// Returns next unread token
	//printf("x:%lld depth:%lld\n",x,depth);
	chkmax(maxdepth,depth);
	vans[depth].PB(x);
	ll k=v[x].second;
	x++;
	for (ll i=0;i<k;i++) {
		x=dfs(x,depth+1);
	}
	return x;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s; cin>>s;
	ll n=s.length();
	{
		ll x=0;
		while(x<n) {
			ll y;
			for (y=x;y<n;y++) {
				if (s[y]==',') break;
			}
			//printf("Ax:%lld y:%lld\n",x,y);
			string tok=s.substr(x,y-x);
			y++;
			x=y;
			for (y=x;y<n;y++) {
				if (s[y]==',') break;
			}
			//printf("Bx:%lld y:%lld\n",x,y);
			string num=s.substr(x,y-x);
			y++;
			x=y;
			ll nu=stoi(num);
			v.PB(MP(tok,nu));
		}
	}
	{
		ll x=0;
		while(x<v.size()) {
			x=dfs(x,0);
		}
	}
	printf("%lld\n",maxdepth+1);
	for (ll d=0;d<=maxdepth;d++) {
		for (auto &x:vans[d]) {
			//printf(" (x:%lld) ",x);
			printf("%s ",v[x].first.c_str());
		}
		printf("\n");
	}
}