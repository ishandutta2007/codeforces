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
const ll MAXM=10000+5;
const ll MAXN=100000+5;
vector<pair<ll,ll> >a[MAXM];
string name[MAXN];
int main() {
	ios_base::sync_with_stdio(false);
	ll n,m; cin>>n>>m;
	for (ll i=0;i<n;i++) {
		cin>>name[i];
		ll r,p;
		cin>>r>>p;
		a[r].PB(MP(p,i));
	}
	for (ll r=1;r<=m;r++) {
		sort(a[r].begin(),a[r].end());
		ll asz=a[r].size();
		if (asz>2&&a[r][asz-2].first==a[r][asz-3].first) {
			cout<<"?\n";
		}
		else {
			cout << name[a[r][asz-1].second] << " " << name[a[r][asz-2].second] << "\n";
		}
	}
}