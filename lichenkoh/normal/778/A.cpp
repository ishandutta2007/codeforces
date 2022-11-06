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
const ll mn=2e5+4;
ll a[mn];
bool take[mn];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	string t,p;
	cin>>t>>p;
	ll tlen=t.length();
	for (ll i=0;i<tlen;i++) {
		cin>>a[i]; --a[i];
	}
	ll plen=p.length();
	ll imin=0,imax=tlen+1;
	while(imin<imax) {
		ll imid=(imin+imax)/2;
		memset(take,0,sizeof take);
		for (ll i=0;i<imid;i++) {
			take[a[i]]=true;
		}
		bool ok=true;
		ll ti=0;
		for (ll pi=0;pi<plen;pi++) {
			while(ti<tlen&&(take[ti]||t[ti]!=p[pi])) ++ti;
			//printf("imid:%lld pi:%lld ti:%lld\n",imid,pi,ti);
			if (ti==tlen) {
				ok=false; break;
			}
			++ti;
		}
		if (ok) imin=imid+1;
		else imax=imid;
	}
	ll ans=imin-1;
	printf("%lld\n",ans);
}