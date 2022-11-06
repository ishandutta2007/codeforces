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
ll f(ll xx) {
	ll x=xx;
	ll two=0;
	while(x>0){
		two+=x/2;
		x/=2;
	}
	ll five=0;
	x=xx;
	while(x>0){
		five+=x/5;
		x/=5;
	}
	return min(two,five);
}
int main() {
	ios_base::sync_with_stdio(false);
	ll n; scanf("%I64d",&n);
	ll lower,upper;
	{
		ll imin=0; ll imax=1000000;
		while(imin<imax) {
			ll imid=imin+(imax-imin)/2;
			if (f(imid)<n) {
				imin=imid+1;
			}
			else {
				imax=imid;
			}
		}
		lower = imin;
	}
	{
		ll imin=0; ll imax=1000000;
		while(imin<imax) {
			ll imid=imin+(imax-imin)/2;
			if (f(imid)<=n) {
				imin=imid+1;
			}
			else {
				imax=imid;
			}
		}
		upper = imin;
	}
	ll k=upper-lower;
	printf("%I64d\n",k);
	for (ll x=lower;x<upper;x++) {
		printf("%I64d ",x);
	}
	printf("\n");
}