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

const int MX = 400005;
int n, m, q, p[MX];
int mx[4 * MX], mn[4 * MX], ex[4 * MX];
multiset<int> in[MX];
set<ii> st;

void build (int i, int j, int pos) {
	mx[pos] = ex[pos] = 0;
	mn[pos] = MX;

	if (i == j) {
		p[i] = pos;
		return;
	}

	int m = (i + j) / 2;
	build(i, m, pos * 2);
	build(m + 1, j, pos * 2 + 1);
}

void update (int x, int y) {
	if (x < 0) in[-x].erase(in[-x].find(y));
	else in[x].insert(y);

	int pos = p[x = abs(x)];

	if (x % 2) mn[pos] = in[x].size() ? *in[x].begin() : MX;
	else mx[pos] = in[x].size() ? *in[x].rbegin() : 0;

	while (pos >>= 1) {
		ex[pos] = ex[pos * 2] || ex[pos * 2 + 1] || mn[pos * 2] < mx[pos * 2 + 1];
		mn[pos] = min(mn[pos * 2], mn[pos * 2 + 1]);
		mx[pos] = max(mx[pos * 2], mx[pos * 2 + 1]);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> q;

	build(1, n * 2, 1);

	while (q--) {
		int x, y;
		cin >> x >> y;

		if (st.count(ii(x, y))) {
			update(-x, y);
			st.erase(ii(x, y));
		} else {
			update(x, y);
			st.emplace(x, y);
		}

		if (ex[1]) cout << "NO" << endl;
		else cout << "YES" << endl;
	}

	return 0;
}