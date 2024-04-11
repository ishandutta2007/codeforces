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
ll a[5000];
int main() {
	ios_base::sync_with_stdio(false);
	ll n; cin>>n;
	for (ll i=0;i<n;i++) {
		cin>>a[i];
	}
	vector<ll> ans;
	for (ll i=0;i<n-1;i++) {
		ans.PB(a[i]);
		if (__gcd(a[i],a[i+1]) > 1) ans.PB(1);
	}
	ans.PB(a[n-1]);
	cout << ans.size()-n << endl;
	for (auto &w:ans) cout << w << " ";
	cout<<endl;
}