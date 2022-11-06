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
typedef pair<ll,ll> pll;
vector<pair<pll,pll> > ans;
ll n;
void check(ll x) {
	assert(x>0&&x<=n);
}
void go(ll x1,ll y1,ll x2,ll y2) {
	check(x1);check(y1);check(x2);check(y2);
	ans.PB(MP(MP(x1,y1),MP(x2,y2)));
}
ll gety(ll x) {
	if (x<=4) return 1;
	else return x-3;
}
ll f[55][55];
ll verify() {
	set<pair<pll,pll> > sans;
	for (auto &w:ans) sans.insert(w);
	memset(f,0,sizeof f);
	f[1][1]=1;
	for (ll s=2;s<=n+n-1;s++) {
		for (ll x=1;x<=n;x++) {
			ll y=s-x;
			if (1<=y&&y<=n) {
				pair<pll,pll> p= MP(MP(x,y),MP(x+1,y));
				if (sans.find(p)==sans.end()) {
					f[x+1][y]+=f[x][y];
				}
				p= MP(MP(x,y),MP(x,y+1));
				if (sans.find(p)==sans.end()) {
					f[x][y+1]+=f[x][y];
				}
			}
		}
	}
	return f[n][n];
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll want; scanf("%lld",&want);
	vector<ll> v;
	while(want>0) {
		v.PB(want%3);
		want/=3;
	}
	reverse(v.begin(),v.end());
	n=v.size()+2;
	{
		ll y=1;
		for (ll x=6;x<=n;x++) {
			go(x-1,y,x,y);
			go(y,x-1,y,x);
			//go(x,y,x,y+1);
			//go(y,x,y+1,x);
			y++;
		}
	}
	{
		ll y=2;
		for (ll x=5;x<=n;x++) {
			go(x-1,y,x,y);
			go(y,x-1,y,x);
			y++;
		}
	}
	go(1,2,2,2);
	go(2,1,2,2);
	for (ll k=0;k<v.size();k++) {
		ll x=k+3;
		if (v[k]<=1) {
			//printf("k:%lld A\n",k);
			go(x,gety(x),x,gety(x)+1);
		}
		if (v[k]<=0) {
			//printf("k:%lld B\n",k);
			go(gety(x),x,gety(x)+1,x);
		}
	}
	printf("%lld %lld\n",n,n);
	printf("%lld\n",(ll)ans.size());
	for (auto &w:ans) {
		printf("%lld %lld %lld %lld\n",
			w.first.first,w.first.second,w.second.first,w.second.second);
	}
	//ll verified=verify();
	//printf("Verify:%lld\n",verified);
}