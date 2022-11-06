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
const ll MAXN=500000+8;
int a[MAXN];
const ll INF=4e9;
int main() {
	ios_base::sync_with_stdio(false);
	int n,k; scanf("%d %d",&n,&k);
	for (ll i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	ll newhi,newlo;
	{
		ll imin=0,imax=INF;
		while(imin<imax) {
			ll imid=imin+(imax-imin)/2;
			ll need=0;
			for (ll i=0;i<n;i++) {
				if(a[i]>imid) need+=a[i]-imid;
			}
			if (need>k) imin=imid+1;
			else imax=imid;
		}
		newhi=imin;
	}
	{
		ll imin=0,imax=INF;
		while(imin<imax) {
			ll imid=imin+(imax-imin)/2;
			ll need=0;
			for (ll i=0;i<n;i++) {
				if(a[i]<imid) need+=imid-a[i];
			}
			if (need<=k) imin=imid+1;
			else imax=imid;
		}
		newlo=imin-1;
	}
	ll sum=0;
	for (ll i=0;i<n;i++) sum+=a[i];
	ll lower=0;
	if ((sum%n)==0) lower=0;
	else lower=1;
	ll ans=max(lower,newhi-newlo);
	cout<<ans<<endl;
}