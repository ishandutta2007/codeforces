#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
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
pair<pll,ll> p[mn];
ll va[mn],vb[mn],vh[mn];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; scanf("%d",&n);
	for (ll i=0;i<n;i++) {
		ll a,b,h;
		scanf("%d%d%d",&a,&b,&h);
		p[i]=MP(MP(b,a),h);
	}
	sort(p,p+n);
	for (ll i=0;i<n;i++) {
		ll b=p[i].fst.fst,a=p[i].fst.snd,h=p[i].snd;
		va[n-1-i]=a;vb[n-1-i]=b;vh[n-1-i]=h;
	}
	map<ll,long long> m;
	for (ll i=0;i<n;i++) {
		long long nh=vh[i];
		auto pt=m.lower_bound(vb[i]);
		if (m.size()>0&&pt!=m.begin()) {
			--pt;
			nh+=pt->second;
		}
		chkmax(m[va[i]],nh);
		auto it=m.find(va[i]);
		++it;
		for (;it!=m.end();) {
			if (it->second<=nh) {
				it=m.erase(it);
			}
			else break;
		}
		//for (auto &w:m) {
		//	printf("%d->%lld, ",w.fst,w.snd);
		//}
		//printf("\n");
	}
	long long best=0;
	for (auto &w:m) chkmax(best,w.second);
	printf("%lld\n",best);
}