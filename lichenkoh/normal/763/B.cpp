#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
int main() {
	ll n;
	scanf("%d",&n);
	printf("YES\n");
	for (ll i=0;i<n;i++) {
		ll x1,y1,x2,y2; scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if (!(x1<=x2)) swap(x1,x2);
		if (!(y1<=y2)) swap(y1,y2);
		ll ans=0;
		if (0!=(x1%2)) ans|=1;
		if (0!=(y1%2)) ans|=2;
		ans++;
		printf("%d\n",ans);
	}

}