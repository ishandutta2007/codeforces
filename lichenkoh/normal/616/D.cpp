#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define MAXE 1000001
#define MAXN 1000001
ll h[MAXE];
ll a[MAXN];
int main() {
	ios_base::sync_with_stdio(false);
	ll n,k; cin >> n >> k;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll cnt = 0;
	ll l = 0;
	ll ans = 0;
	pair<ll,ll> best;
	for (ll r = 0; r < n; r++) {
		h[a[r]]++;
		if (h[a[r]] == 1) cnt++;
		while (cnt > k) {
			h[a[l]]--;
			if (h[a[l]] == 0) cnt--;
			l++;
		}
		ll cand = r-l+1;
		if (cand > ans) {
			best = MP(l,r);
			ans = cand;
		}
	}
	cout << best.first+1 << " " << best.second+1 << endl;
}