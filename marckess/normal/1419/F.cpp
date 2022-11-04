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

const int MX = 1005, inf = int(2e9) + 5;
int n, f[MX], p[MX], sz;
vii a;
map<ii, set<int>> mp;
vi t[2 * MX * MX], d[2 * MX * MX];

int parent (int a) {
	return a == p[a] ? a : p[a] = parent(p[a]);
}

void join (int a, int b) {
	p[parent(a)] = parent(b);
}

int dis (const ii &a, const ii &b) {
	return abs(a.fi - b.fi) + abs(a.se - b.se);
}

bool esPos (int m) {
	iota(p, p + n, 0);

	forn (i, n) forn (j, i)
		if (a[i].fi == a[j].fi || a[i].se == a[j].se)
			if (dis(a[i], a[j]) <= m)
				join(i, j);

	set<int> st;
	forn (i, n)
		st.insert(parent(i));

	if (st.size() > 4) return 0;
	if (st.size() == 1) return 1;

	int mk = 0;
	for (int x : st)
		f[x] = mk++;

	forn (i, n) f[i] = f[p[i]];

	forn (i, sz) {
		int mk = 0;

		forn (j, t[i].size())
			if (d[i][j] <= m)
				mk |= 1 << f[t[i][j]];
		
		if (__builtin_popcount(mk) == st.size())
			return 1;
	}

	return 0;
}

void insert (int i, int j, const ii &p) {
	mp[p].insert(i);
	mp[p].insert(j);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	a.resize(n);
	forn (i, n) cin >> a[i].fi >> a[i].se;

	forn (i, n) forn (j, i) {
		if (a[i].fi == a[j].fi)
			insert(i, j, {a[i].fi, (a[i].se + a[j].se) / 2});
		else if (a[i].se == a[j].se)
			insert(i, j, {(a[i].fi + a[j].fi) / 2, a[i].se});
		else
			insert(i, j, {a[i].fi, a[j].se}),
			insert(i, j, {a[j].fi, a[i].se});
	}

	for (const auto &it : mp) {
		for (const int &jt : it.se) {
			t[sz].pb(jt);
			d[sz].pb(dis(it.fi, a[jt]));
		}
		sz++;
	}

	int i = 1, j = inf, rep = 32;
	while (rep--) {
		int m = (1ll + i + j) / 2;
		if (esPos(m)) j = m;
		else i = m;
	}

	if (j == inf) cout << -1 << endl;
	else cout << j << endl;

	return 0;
}