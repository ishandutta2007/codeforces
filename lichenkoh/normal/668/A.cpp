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
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
ll ans[108][108];
int main() {
	ios_base::sync_with_stdio(false);
	ll n,m,q;
	scanf("%d %d %d",&n,&m,&q);
	for (ll r=0;r<n;r++) {
		for (ll c=0;c<m;c++) {
			ans[r][c]=0;
		}
	}
	vector<pair<ll,ll> > v;
	for (ll k=0;k<q;k++) {
		ll t; scanf("%d",&t);
		if (t==1||t==2) {
			ll ri; scanf("%d",&ri);
			ri--;
			v.PB(MP(t,ri));
		}
		else {
			ll r,c,xv; scanf("%d %d %d",&r,&c,&xv);
			r--; c--;
			ll vsz=v.size();
			for (ll j=vsz-1;j>=0;j--) {
				pair<ll,ll> w=v[j];
				if (w.first==1&&w.second==r) {
					c=(c+1)%m;
				}
				else if (w.first==2&&w.second==c) {
					r=(r+1)%n;
				}
			}
			ans[r][c]=xv;
		}
	}
	for (ll r=0;r<n;r++) {
		for (ll c=0;c<m;c++) {
			printf("%d ",ans[r][c]);
		}
		printf("\n");
	}
}