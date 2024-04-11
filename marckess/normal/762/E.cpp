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

const int MX = 100005, inf = 2e9 + 5;
int n, k, x[MX], r[MX], f[MX], ft[MX], ft2[MX];
ll res;
vi pos[MX];

void update (int i, int k, int ft[]) {
	while (i < MX) {
		ft[i] += k;
		i += i & -i;
	}
}

int query (int i, int ft[]) {
	int s = 0;
	while (i) {
		s += ft[i];
		i -= i & -i;
	}
	return s;
}

int query (int a, int b, int ft[]) {
	if (a > b) return 0;
	return query(b, ft) - query(a - 1, ft);
}

void solve (vii &v) {
	sort(all(v));
	set<ii> st;

	forn (i, v.size()) {
		st.emplace(v[i].fi + abs(v[i].se), i);

		while (st.size() && st.begin()->fi < v[i].fi) {
			auto it = st.begin();

			update(it->se + 1, -1, ft);
			if (v[it->se].se > 0) update(it->se + 1, -1, ft2);
			
			st.erase(it);
		}

		int j = lower_bound(all(v), ii(v[i].fi - abs(v[i].se), -inf)) - v.begin();
		if (v[i].se > 0) res += query(j + 1, i + 1, ft);
		else res += query(j + 1, i + 1, ft2);

		update(i + 1, 1, ft);
		if (v[i].se > 0) update(i + 1, 1, ft2);
	}

	while (st.size()) {
		auto it = st.begin();

		update(it->se + 1, -1, ft);
		if (v[it->se].se > 0) update(it->se + 1, -1, ft2);
		
		st.erase(it);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;

	forn (i, n) {
		cin >> x[i] >> r[i] >> f[i];
		pos[f[i]].pb(i);
	}

	for (int i = 1; i < MX; i++)
		if (pos[i].size()) {
			vii v;

			for (int j = max(1, i - k); j <= i; j++)
				for (int p : pos[j])
					v.emplace_back(x[p], j == i ? r[p] : -r[p]);

			solve(v);
		}

	cout << res << endl;

	return 0;
}