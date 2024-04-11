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
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll MAXN=1e4+4;
pair<ll,ll> p[MAXN];
int main() {
	ios_base::sync_with_stdio(false);
	cout<<fixed<<setprecision(9);
	ll n,w,v,u; scanf("%I64d %I64d %I64d %I64d",&n,&w,&v,&u);
	for (ll i=0;i<n;i++) {
		scanf("%I64d %I64d",&p[i].first,&p[i].second);
	}
	pair<pair<ll,ll>, ll> bot=MP(p[0],0LL),top=MP(p[0],0LL);
	for (ll i=0;i<n;i++) {
		pair<ll,ll> q=p[i];
		if (q.second<=bot.first.second) bot=MP(q,i);
		if (q.second>=top.first.second) top=MP(q,i);
	}
	//assert(top.second!=bot.second);
	// Left
	bool ok=true;
	for (ll i=top.second;;i=(i+1)%n) {
		ll x=p[i].first,y=p[i].second;
		if (x*u<y*v) ok=false;
		if (i==bot.second) break;
	}
	if (ok) {
		ld ans=(ld)w/(ld)u;
		cout<<ans<<endl;
		return 0;
	}
	ll prevy=0;
	ld prevt=0;
	for (ll i=bot.second;;i=(i+1)%n) {
		ll x=p[i].first,y=p[i].second;
		ld tbus=(ld)x/((ld)v);
		ld tped=prevt+((ld)(y-prevy)/((ld)u));
		prevt=max(tbus,tped);		
		prevy=y;
		if (i==top.second) break;
	}
	ld ans=prevt+(ld)(w-prevy)/((ld)u);
	cout<<ans<<endl;
}