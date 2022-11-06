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
	ll n,k; cin>>n>>k;
	k=min(k,n/2);
	ll ans=0;
	for (ll i=0;i<k;i++) {
		ans += (n-1)+(n-2);
		n-=2;
	}
	cout << ans << endl;
}