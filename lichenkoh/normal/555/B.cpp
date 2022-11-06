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
const int mn=2e5+4;
ll vl[mn],vr[mn];
int vans[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n,m; scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) {
		scanf("%lld%lld",&vl[i],&vr[i]);
	}
	map<ll,vector<int> > sa;
	for (int i=1;i<=m;i++) {
		ll a; scanf("%lld",&a); sa[a].PB(i);
	}
	vector<pair<pll,int> > vd;
	for (int i=0;i<n-1;i++) {
		ll hi=vr[i+1]-vl[i];
		ll lo=vl[i+1]-vr[i];
		//printf("lo:%lld hi:%lld\n",lo,hi);
		vd.PB(MP(MP(hi,lo),i));
	}
	sort(vd.begin(),vd.end());
	for (auto &w:vd) {
		ll lo=w.fst.snd,hi=w.fst.fst;
		int island_idx=w.snd;
		auto it=sa.lower_bound(lo);
		bool ok=false;
		if (it!=sa.end()) {
			ll x=it->first;
			if (lo<=x&&x<=hi) {
				vans[island_idx]=it->snd.back();
				it->snd.pop_back();
				if (it->snd.size()==0) sa.erase(it);
				ok=true;
			}
		}
		if (!ok) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	for (int i=0;i<n-1;i++) printf("%d ",vans[i]);
	printf("\n");
}