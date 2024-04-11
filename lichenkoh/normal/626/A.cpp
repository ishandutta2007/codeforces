#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
int main() {
	ios_base::sync_with_stdio(false);
	ll n; cin >> n;
	string s; cin >> s;
	ll ans = 0;
	for (ll x=0;x<n;x++) {
		for (ll y=x;y<n;y++) {
			ll px=0; ll py=0;
			for (ll i=x;i<=y;i++) {
				if (s[i]=='U') py++;
				else if (s[i]=='D') py--;
				else if (s[i]=='R') px++;
				else if (s[i]=='L') px--;
				else assert(false);
			}
			if (px==0&&py==0) ans++;
		}
	}
	cout << ans << endl;
}