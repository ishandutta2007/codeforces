#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007LL
#define UNDEF -1LL
#define PB push_back
#define MP make_pair
#define HOUSE 0
#define FIRST 1
#define SECOND 2
int main() {
	ios_base::sync_with_stdio(false);
	ll d1,d2,d3;
	cin >> d1; cin >> d2; cin >> d3;
	ll a[3][3];
	for (ll i = 0; i < 3; i++) {
		for (ll j = 0; j < 3; j++) {
			a[i][j] = 0;
		}
	}
	a[HOUSE][FIRST] = min(d1, d2+d3);
	a[FIRST][HOUSE] = min(d1, d2+d3);

	a[HOUSE][SECOND] = min(d2, d1+d3);
	a[SECOND][HOUSE] = min(d2, d1+d3);

	a[FIRST][SECOND] = min(d3, d1+d2);
	a[SECOND][FIRST] = min(d3, d1+d2);

	// Vist first, then second
	ll ans1 = a[HOUSE][FIRST] + a[FIRST][SECOND] + a[SECOND][HOUSE];
	ll ans2 = a[HOUSE][SECOND] + a[SECOND][FIRST] + a[FIRST][HOUSE];
	ll ans = min(ans1, ans2);
	cout << ans << endl;
}