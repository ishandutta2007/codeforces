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
const ll INF=1e9+50;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const ll mn=1e5+4;
ll st[mn];
ll u[mn],v[mn],l[mn];
int main() {
	ios_base::sync_with_stdio(false);
	ll n,m,k; scanf("%d %d %d",&n,&m,&k);
	for (ll i=0;i<m;i++) {
		scanf("%d %d %d",&u[i],&v[i],&l[i]);
	}
	for (ll i=0;i<mn;i++) st[i]=0;
	for (ll i=0;i<k;i++) {
		ll a;scanf("%d",&a);
		st[a]=1;
	}
	ll ans=1e9+50;
	for (ll i=0;i<m;i++) {
		ll x=u[i],y=v[i],len=l[i];
		if (st[x]^st[y]) chkmin(ans,len);
	}
	if (ans>=1e9+5) printf("-1\n");
	else printf("%d\n", ans);
}