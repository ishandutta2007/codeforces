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
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const ll mn=3e5+4;
int a[mn];
int main() {
	ios_base::sync_with_stdio(false);
	int n; scanf("%d",&n);
	for (ll i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	ll med=(n-1)/2;
	printf("%d\n",a[med]);
}