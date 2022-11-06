#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MX = 1000006;
const ll inf = 1e18;
ll n, m, p, a[MX], ca[MX], b[MX], cb[MX], mn[MX];
ll x[MX], y[MX], z[MX];
ll st[4 * MX + 20], lz[4 * MX + 20], res = -inf;
vi pos[MX];

void push (int i, int j, int pos) {
	if (i < j) {
		lz[pos * 2] += lz[pos];
		lz[pos * 2 + 1] += lz[pos];
	}
	st[pos] += lz[pos];
	lz[pos] = 0;
}

void update (int i, int j, int pos, int a, int b, ll k) {
	if (lz[pos]) push(i, j, pos);
	if (j < a || b < i) return;
	if (a <= i && j <= b) {
		lz[pos] = k;
		push(i, j, pos);
		return;
	}
	int m = (i + j) / 2;
	update(i, m, pos * 2, a, b, k);
	update(m + 1, j, pos * 2 + 1, a, b, k);
	st[pos] = max(st[pos * 2], st[pos * 2 + 1]);
}

ll query (int i, int j, int pos, int a, int b) {
	if (lz[pos]) push(i, j, pos);
	if (j < a || b < i) return -inf;
	if (a <= i && j <= b) return st[pos];
	int m = (i + j) / 2;
	return max(
		query(i, m, pos * 2, a, b),
		query(m + 1, j, pos * 2 + 1, a, b)
	);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> p;

	fill(mn, mn + MX, inf);
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> ca[i];
		mn[a[i]] = min(mn[a[i]], ca[i]);
	}

	for (int i = 1; i < MX; i++)
		update(1, MX - 1, 1, i, i, -mn[i]);

	fill(mn, mn + MX, inf);
	for (int i = 1; i <= m; i++) {
		cin >> b[i] >> cb[i];
		mn[b[i]] = min(mn[b[i]], cb[i]);
	}

	for (int i = 1; i <= p; i++) {
		cin >> x[i] >> y[i] >> z[i];
		pos[y[i]].pb(i);
	}

	for (int i = 1; i < MX - 1; i++) {
		for (int j : pos[i - 1])
			update(1, MX - 1, 1, x[j] + 1, MX - 1, z[j]);

		push(1, MX - 1, 1);
		res = max(res, st[1] - mn[i]);
	}

	cout << res << endl;

	return 0;
}