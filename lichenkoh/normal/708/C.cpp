#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const ll mn=4e5+4;
vector<ll> g[mn];
bool bad[mn];
ll n;
vector<pair<ll,ll> > largest_good_subtree_list[mn];
ll subtree_size_array[mn];
pair<ll,ll> dfs1(ll x, ll p) {
	pair<ll,ll> largest_good_subtree=MP(0ll, -1ll);
	ll sum_size=1;
	for (auto &y:g[x]) {
		if (y==p) continue;
		pair<ll,ll> pget=dfs1(y,x);

		ll child_size=pget.first;
		sum_size+=child_size;

		ll child_largest_good_subtree=pget.second;
		ll candidate_largest_good_subtree = child_largest_good_subtree;
		if (child_size <= n/2) chkmax(candidate_largest_good_subtree, child_size);
		largest_good_subtree_list[x].PB(MP(candidate_largest_good_subtree, y));
		chkmax(largest_good_subtree, MP(candidate_largest_good_subtree, y));
	}
	sort(largest_good_subtree_list[x].begin(), largest_good_subtree_list[x].end(), greater<pair<ll,ll> >());
	ll tmp_variable=min(2,(ll)largest_good_subtree_list[x].size());
	largest_good_subtree_list[x].resize(tmp_variable);
	subtree_size_array[x]=sum_size;
	return MP(sum_size, largest_good_subtree.first);
}
pair<ll, ll> parent_best[mn];
void solve(ll x, ll p) {
	for (auto &y:g[x]) {
		if (y==p) continue;
		pair<ll,ll> savior = MP(0ll,-1ll);
		if (largest_good_subtree_list[y].size() > 0) {
			savior = largest_good_subtree_list[y][0];
		}
		assert(savior.first <= n/2);
		ll left=subtree_size_array[y] - savior.first;
		//printf("x:%d y:%d savior_size:%d savior_vertex:%d left:%d n/2:%d\n",x,y,savior.first,savior.second,left,n/2);
		if (left > n/2) {
			bad[x] = true;
		}
	}
	if (p!=-1) {
		pair<ll,ll> savior = parent_best[p];
		assert(savior.first <= n/2);
		ll parent_subtree_size_upwards = n - subtree_size_array[x];
		ll left = parent_subtree_size_upwards - savior.first;
		//printf("x:%d p:%d savior_size:%d savior_vertex:%d left:%d n/2:%d\n",x,p,savior.first,savior.second,left,n/2);
		if (left > n/2) {
			bad[x] = true;
		}
	}
	for (auto &y:g[x]) {
		if (y==p) continue;
		pair<ll,ll> savior_for_y = MP(0ll,-1ll);
		for (auto &w: largest_good_subtree_list[x]) {
			ll z_vertex = w.second;
			if (z_vertex == y) continue;
			chkmax(savior_for_y, w);
			break;
		}
		if (p!=-1) {
			chkmax(savior_for_y, parent_best[p]);
			ll parent_subtree_size_upwards = n - subtree_size_array[x];
			if (parent_subtree_size_upwards <= n/2) {
				chkmax(savior_for_y, MP(parent_subtree_size_upwards,p));
			}
		}
		parent_best[x] = savior_for_y;
		solve(y, x);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	scanf("%d",&n);
	for (ll i=0;i<n-1;i++) {
		ll x,y;scanf("%d %d",&x,&y);
		g[x].PB(y);g[y].PB(x);
	}
	for (ll x=0;x<=n;x++) bad[x]=false;
	dfs1(1,-1);
	solve(1,-1);
	for (ll x=1;x<=n;x++) {
		printf("%d ",bad[x]?0:1);
	}
	printf("\n");
}