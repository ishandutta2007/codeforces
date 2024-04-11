#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 205, mod = 1e9+7;
int n;
ii p[MX];
ll dp[MX][MX], s = 0;

ii operator - (ii a, ii b) {
	return {a.fi - b.fi, a.se - b.se};
}

ll operator ^ (ii a, ii b) {
	return a.fi * b.se - a.se * b.fi;
}

bool operator <= (ii a, ii b) {
	//if (a == b) return 1;
	return a.fi ^ b.fi ? a.fi < b.fi : a.se < b.se;
}

ll area (int i, int j) {
	ll res = 0;
	if (i > j) j += n;
	if (j - i <= 1) return s;

	for (int k = 0, m = j - i + 1; k < m; k++) {
		res += p[(i+k)%n] ^ p[(i+(k+1)%m)%n];
	}
	return res;
}

bool inter (int i, int j) {
	ii a = p[i], b = p[j];
	for (int k = 0; k < n; k++)
		if (i != k && j != (k+1)%n) {
			ii c = p[k], d = p[(k+1)%n];

			ll w = (b - a) ^ (c - a);
			ll x = (b - a) ^ (d - a);
			ll y = (d - c) ^ (a - c);
			ll z = (d - c) ^ (b - c);

			if (!w) {
				if (a <= c && c <= b) return 1;
				if (b <= c && c <= a) return 1;
			}

			if (!x) {
				if (a <= d && d <= b) return 1;
				if (b <= d && d <= a) return 1;
			}

			if (!y) {
				if (c <= a && a <= d) return 1;
				if (d <= a && a <= c) return 1;
			}

			if (!z) {
				if (c <= b && b <= d) return 1;
				if (d <= b && b <= c) return 1;
			}

			if (w && x && y && z && w < 0 != x < 0 && y < 0 != z < 0)
				return 1;
		}

	return 0;
}

ll obtRes (int i, int j) {
	ll &res = dp[i][j];
	if (res != -1) return res;
	res = 0;

	if (j < i == 1)
		return res = 1;

	if (s * area(i, j) <= 0 || s * area(j, i) <= 0 || inter(i, j))
		return res;

	if (j - i < 2)
		return res = 1;

	for (int k = i + 1; k < j; k++)
		res += obtRes(i, k) * obtRes(k, j) % mod;

	return res %= mod;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(dp, -1, sizeof(dp));

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i].fi >> p[i].se;

	s = area(0, n-1);
	s /= abs(s);
	
	cout << obtRes(0, n-1) << endl;

	return 0;
}