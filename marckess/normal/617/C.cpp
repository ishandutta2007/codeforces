#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 2005;
int n;
ll x, y, x2, y2, a[MX], b[MX];

ll dis (ll x, ll y, ll x2, ll y2) {
	return (x - x2) * (x - x2) + (y - y2) * (y - y2);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> x >> y >> x2 >> y2;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];

	ll res = 1e18;
	for (int i = 0; i < n; i++) {
		ll d = dis(x, y, a[i], b[i]);
		ll e = 0;
		for (int j = 0; j < n; j++)
			if (d < dis(x, y, a[j], b[j]))
				e = max(e, dis(x2, y2, a[j], b[j]));
		res = min(res, d + e);
	}

	swap(x, x2);
	swap(y, y2);
	for (int i = 0; i < n; i++) {
		ll d = dis(x, y, a[i], b[i]);
		ll e = 0;
		for (int j = 0; j < n; j++)
			if (d < dis(x, y, a[j], b[j]))
				e = max(e, dis(x2, y2, a[j], b[j]));
		res = min(res, d + e);
	}

	cout << res << endl;

	return 0;
}