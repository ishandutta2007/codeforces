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
int a[100000+8];
int main() {
	ios_base::sync_with_stdio(false);
	int n,k; scanf("%d %d",&n,&k);
	for (ll i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	ll imin=0,imax=1e9;
	while(imin<imax) {
		ll imid=imin+(imax-imin)/2;
		ll s=(imid*(imid+1))/2;
		if (s<k) imin=imid+1;
		else imax=imid;
	}
	imin--;
	ll ans=k-(imin*(imin+1))/2;
	//cout<<imin<<" "<<ans<<endl;
	ll final=a[ans-1];
	cout<<final<<endl;
}