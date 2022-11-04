#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 505;
int n, k, a[MX], b[MX];
ll mem[MX][MX];

ll dp (int i, int f, int g) {
	if (i == n) return 0;

	ll &res = mem[i][f];
	if (res != -1) return res;

	res = dp(i + 1, (f + a[i]) % k, (g + b[i]) % k) + (f + a[i]) / k + (g + b[i]) / k;

	for (int t = 0; t <= min(a[i], k - 1); t++) {
		if (a[i] - t + b[i] < k) continue;

		ll x = (a[i] - t + b[i]) / k;
		ll y = (a[i] - t + b[i]) % k;

		if (y > b[i]) continue;

		ll ar = f + t, as = 0;
		if (ar >= k) {
			ar -= k;
			as = 1;
		}

		ll br = g + y, bs = 0;
		if (br >= k) {
			br -= k;
			bs = 1;
		}

		res = max(
			res,
			dp(i + 1, ar, br) + x + as + bs
		);
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;	
	forn (i, n) cin >> a[i] >> b[i];

	memset(mem, -1, sizeof(mem));
	cout << dp(0, 0, 0) << endl;

	return 0;
}