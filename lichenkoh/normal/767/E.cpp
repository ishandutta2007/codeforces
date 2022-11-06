#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
const ll mn=1e5+4;
ll c[mn],w[mn];
vll vx,vp;
bool used[mn];
ll oldtonew[mn];
ll canuse[mn];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,m; cin>>n>>m;
	for (ll i=0;i<n;i++) cin>>c[i];
	for (ll i=0;i<n;i++) cin>>w[i];
	for (ll i=0;i<n;i++) {
		if (c[i]%100!=0) {
			ll x=100-(c[i]%100);
			oldtonew[i]=vx.size();
			vx.PB(x);
			vp.PB(w[i]*x);
		}
		else oldtonew[i]=-1;
	}
	ll lhs=m;
	ll k=vx.size();
	ll ans=0;
	for (ll i=0;i<k;i++) {
		lhs+=vx[i];
		canuse[i]=lhs/100;
	}
	set<pll, greater<pll> > s;
	for (ll i=k-1;i>=0;i--) {
		s.insert(MP(vp[i],i));
		ll thisuse=canuse[i]-((i==0)?0ll:canuse[i-1]);
		ll go=min(thisuse,(ll)s.size());
		for (ll i=0;i<go;i++) {
			auto it=s.begin();
			used[it->second]=true;
			s.erase(it);
		}
	}
	for (ll i=0;i<k;i++) {
		if (!used[i]) ans+=vp[i];
	}
	printf("%lld\n",ans);
	for (ll i=0;i<n;i++) {
		ll t=oldtonew[i];
		if (t==-1||used[t]) {
			printf("%lld %lld\n",c[i]/100,c[i]%100);
		}
		else printf("%lld %lld\n",(c[i]+99)/100,0ll);
	}
}