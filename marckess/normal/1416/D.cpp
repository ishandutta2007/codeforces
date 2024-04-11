#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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

const int MX = 500005;
int n, m, q, a[MX], inv[MX];
int u[MX], v[MX], del[MX];
int t[MX], x[MX], res[MX];

int p[MX], rk[MX], in[MX];
set<int> st[MX];

int parent (int a, int time) {
	while (a != p[a] && time <= in[a])
		a = p[a];
	return a;
}

void join (int a, int b, int time) {
	a = parent(a, -1);
	b = parent(b, -1);

	if (a == b) return;

	if (rk[a] < rk[b]) swap(a, b);

	p[b] = a;
	in[b] = time;
	if (rk[a] == rk[b]) rk[a]++;
}

void solve () {
	cin >> n >> m >> q;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		inv[a[i]] = i;
	}

	for (int i = 1; i <= m; i++)
		cin >> u[i] >> v[i];

	forn (i, q) {
		cin >> t[i] >> x[i];

		if (t[i] == 2)
			del[x[i]] = 1;
	}

	iota(p, p + MX, 0);
	memset(in, -1, sizeof(in));

	for (int i = 1; i <= m; i++)
		if (!del[i])
			join(u[i], v[i], q + 1);

	for (int i = q - 1; i >= 0; i--)
		if (t[i] == 2)
			join(u[x[i]], v[x[i]], i);

	forn (i, q) {
		if (t[i] == 1) {
			int v = parent(x[i], i);
			st[v].insert(i);
		}
	}

	for (int i = n; i > 0; i--) {
		int mn = q + 1, ind = -1, time = q + 1;
		int u = inv[i];

		while (1) {
			if (st[u].size()) {
				if (*st[u].begin() < mn && *st[u].begin() <= time) {
					mn = *st[u].begin();
					ind = u;
				}
			}

			if (u == p[u]) break;

			time = min(time, in[u]);
			u = p[u];
		}

		if (ind != -1) {
			res[mn] = i;
			st[ind].erase(mn);
		}
	}

	forn (i, q)
		if (t[i] == 1)
			cout << res[i] << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--)	
		solve();

	return 0;
}