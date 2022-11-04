#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 882000;
vi pos[MX];
int n, g[MX];
ll a[MX];

int s2 (ll n) {
	int i = 0, j = 882000, rep = 21;

	while (rep--) {
		ll m = (i+j)/2;
		if (m * m <= n) i = m;
		else j = m;
	}

	return i;
}

int s4 (ll n) {
	int i = 0, j = 1000, rep = 13;

	while (rep--) {
		ll m = (i+j)/2;
		if (m * m * m * m >= n) j = m;
		else i = m;
	}

	return j;
}

int mex (int a, int b) {
	if (a > b) return 0;
	for (int i = 0;; i++) {
		auto it = lower_bound(ALL(pos[i]), a);
		if (it == pos[i].end() || *it > b)
			return i;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; cin >> a[i++]);

	for (int i = 0; i < 4; i++) pos[0].push_back(i);
	for (int i = 4; i < MX; i++) {
		g[i] = mex(s4(i), s2(i));
		pos[g[i]].push_back(i);
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < MX) res ^= g[a[i]];
		else res ^= mex(s4(a[i]), s2(a[i]));
	}

	if (res) cout << "Furlo" << endl;
	else cout << "Rublo" << endl;

	return 0;
}