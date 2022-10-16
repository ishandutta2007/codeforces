#include <stdio.h>
#include <set>
#include <algorithm>
#include <assert.h>
typedef long long ll;
const ll MAXN = 58;
ll a[MAXN][MAXN];
ll ans[MAXN];
bool done[MAXN];
using namespace std;
int main() {
	ll n; scanf("%lld", &n);
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			scanf("%lld",&a[i][j]);
		}
	}
	for (ll i = 1; i <= n; i++) {
		done[i] = false;
	}
	for (ll x = 1; x <= n; x++) {
		for (ll i = 1; i <= n; i++) {
			if (done[i]) continue;
			bool good = true;
			for (ll j = 1; j <= n; j++) {
				good = good && (a[i][j] <= x);
			}
			if (good) {
				ans[i] = x;
				done[i] = true;
				break;
			}
		}
	}
	// Check
	set<ll> seen;
	for (ll i = 1; i <= n; i++) {
		assert(1 <= ans[i] <= n);
		seen.insert(ans[i]);
	}
	assert(seen.size() == n);
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			if (i==j) continue;
			assert(a[i][j] == min(ans[i],ans[j]));
		}
	}
	for (ll i = 1; i <= n; i++) {
		printf("%lld ",ans[i]);
	}
	printf("\n");
}