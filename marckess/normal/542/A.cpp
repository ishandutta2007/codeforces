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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, m, p[MX], q[MX], x, y;
int l[MX], r[MX];
int a[MX], b[MX];
ll c[MX], res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	
	forn (i, n) cin >> l[i] >> r[i];
	forn (i, m) cin >> a[i] >> b[i] >> c[i];

	iota(p, p + n, 0);
	iota(q, q + m, 0);

	sort(p, p + n, [&] (int i, int j) { return l[i] < l[j]; });
	sort(q, q + m, [&] (int i, int j) { return a[i] < a[j]; });

	int _i = 0, _j = 0, to = -1, ind;

	while (_j < m) {
		int i, j = q[_j];

		while (_i < n && l[i = p[_i]] <= a[j]) {
			if (to < r[i]) {
				to = r[i];
				ind = i;
			}
			_i++;
		}

		ll k = c[j] * (min(to, b[j]) - a[j]);

		if (k > res) {
			res = k;
			x = ind, y = j;
		}

		_j++;
	}

	sort(p, p + n, [&] (int i, int j) { return r[i] > r[j]; });
	sort(q, q + m, [&] (int i, int j) { return b[i] > b[j]; });

	_i = 0, _j = 0, to = 2e9, ind;

	while (_j < m) {
		int i, j = q[_j];

		while (_i < n && r[i = p[_i]] >= b[j]) {
			if (to > l[i]) {
				to = l[i];
				ind = i;
			}
			_i++;
		}

		ll k = c[j] * (b[j] - max(to, a[j]));

		if (k > res) {
			res = k;
			x = ind, y = j;
		}

		_j++;
	}

	sort(p, p + n, [&] (int i, int j) { return l[i] < l[j]; });
	sort(q, q + m, [&] (int i, int j) { return a[i] < a[j]; });

	_i = 0, _j = 0;
	set<ii> st;

	while (_i < n) {
		int i = p[_i], j;

		while (_j < m && a[j = q[_j]] <= l[i]) {
			auto it = st.lower_bound({b[j], MX});

			while (it != st.begin()) {
				auto jt = it;
				jt--;
				if (c[jt->se] < c[j]) st.erase(jt);
				else break;
			}

			it = st.lower_bound({b[j], -1});
			if (it == st.end() || c[j] > c[it->se])
				st.emplace(b[j], j);

			_j++;
		}

		auto it = st.lower_bound({r[i], -1});
		if (it != st.end()) {

			ll k = c[it->se] * (r[i] - l[i]);
			
			if (k > res) {
				res = k;
				x = i, y = it->se;
			}
		}

		_i++;
	}

	cout << res << endl;
	if (res) cout << x + 1 << " " << y + 1 << endl;

	return 0;
}