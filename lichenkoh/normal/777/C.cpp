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
const ll INF=1e9+4;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

const ll mn=1e5+2;
const ll smn=sqrt(mn);
vector<ll> a[mn];
ll b[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,m; scanf("%d%d",&n,&m);
	for (ll x=0;x<n;x++) {
		a[x].resize(m);
		for (ll y=0;y<m;y++) {
			scanf("%d",&a[x][y]);
		}
	}
	for (ll y=0;y<m;y++) {
		chkmax(b[n-1],n-1);
		ll now=n-1;
		for (ll x=n-2;x>=0;x--) {
			if (a[x][y]>a[x+1][y]) {
				now=x;
			}
			//printf("y:%d x:%d now:%d\n",y,x,now);
			chkmax(b[x],now);
		}
	}
	ll k; scanf("%d",&k);
	for (ll i=0;i<k;i++) {
		ll l,r; scanf("%d%d",&l,&r); --l; --r;
		if (b[l]>=r) printf("Yes\n");
		else printf("No\n");
	}
}