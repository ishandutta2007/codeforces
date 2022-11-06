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
int main() {
	ios_base::sync_with_stdio(false);
	ll a,b,c;
	cin >> a >> b >> c;
	bool ok=false;
	const ll n=50000;
	for (ll y=0;y<n;y++) {
		ll num = c-b*y;
		if (num%a == 0) {
			ll x=num/a;
			if (x>=0) {
				ok=true;
				break;
			}
		}
	}
	if(ok) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
}