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
const ll INF=1ULL<<30ULL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
int main() {
	ios_base::sync_with_stdio(false);
	ll n; scanf("%d",&n);
	ll lo=INF,hi=-INF;
	for (ll s=0;s<8;s++) {
		ll x=0;
		for (ll i=0;i<n;i++) {
			if ((i%7)==s%7||(i%7)==(s+1)%7) {
				x++;
			}
		}
		chkmin(lo,x);
		chkmax(hi,x);
	}
	printf("%d %d\n",lo,hi);
}