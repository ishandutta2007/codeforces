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
ll a[100];
set<ll> s;
int main() {
	ios_base::sync_with_stdio(false);
	ll n; cin>>n;
	for (ll i=0;i<n;i++) {ll x;cin>>x;s.insert(x);}
	ll idx=0;
	for (auto &w:s) {
		a[idx]=w;
		idx++;
	}
	bool ok=false;
	for (ll i=0;i<idx-2;i++) {
		if(a[i+2]-a[i]<=2) {
			ok=true;
		}
	}
	if(ok) printf("YES\n");
	else printf("NO\n");
}