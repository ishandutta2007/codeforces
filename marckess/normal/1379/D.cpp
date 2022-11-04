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

typedef pair<ii, int> seg;

const int MX = 100005;
int n, h, m, k, a[MX];
vector<seg> v;
vi events, res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> h >> m >> k;
	
	forn (i, n) {
		int kk;
		cin >> kk >> a[i];
		if (a[i] >= m / 2) a[i] -= m / 2;

		if (k == 1) {
			v.emplace_back(ii(0, m / 2 - 1), i);
		} else {
			int to = a[i] - (m / 2 - k);

			if (to >= 0) {
				v.emplace_back(ii(to, a[i]), i);
			} else {
				v.emplace_back(ii(0, a[i]), i);
				v.emplace_back(ii(to + m / 2, m / 2 - 1), i);
			}
		}
	}

	sort(all(v));

	int mx = 0, ind = 0;
	set<ii> st;

	for (auto it : v) {
		while (st.size() && st.begin()->fi < it.fi.fi)
			st.erase(st.begin());
		st.emplace(it.fi.se, it.se);

		if (mx < st.size()) {
			mx = st.size();
			ind = it.fi.fi;
		}
	}

	set<int> si;
	for (auto it : v)
		if (it.fi.fi <= ind && ind <= it.fi.se)
			si.insert(it.se);

	forn (i, n) if (!si.count(i)) res.pb(i);

	cout << res.size() << " " << ind << endl;
	for (int r : res)
		cout << r + 1 << " ";
	cout << endl;

	return 0;
}