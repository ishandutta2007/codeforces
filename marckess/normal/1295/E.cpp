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
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const ll inf = 1e18;
const int MX = 200005;
ll st[4 * MX], mn[4 * MX], lz[4 * MX];

void push (int i, int j, int pos) {
	mn[pos] += lz[pos];
	if (i < j) {
		lz[2 * pos] += lz[pos];
		lz[2 * pos + 1] += lz[pos];
	}
	lz[pos] = 0;
}

void build (int i, int j, int pos) {
	st[pos] = i;
	if (i == j) return;
	int m = (i + j) / 2;
	build(i, m, 2 * pos);
	build(m + 1, j, 2 * pos + 1);
}

void update (int i, int j, int pos, int a, int b, int k) {
	if (lz[pos]) push(i, j, pos);
	if (j < a || b < i) return;
	if (a <= i && j <= b) {
		lz[pos] = k;
		push(i, j, pos);
		return;
	}
	int m = (i + j) / 2;
	update(i, m, 2 * pos, a, b, k);
	update(m + 1, j, 2 * pos + 1, a, b, k);
	if (mn[2 * pos] < mn[2 * pos + 1]) {
		st[pos] = st[2 * pos];
		mn[pos] = mn[2 * pos];
	} else {
		st[pos] = st[2 * pos + 1];
		mn[pos] = mn[2 * pos + 1];
	}
}

ii query (int i, int j, int pos, int a, int b) {
	if (lz[pos]) push(i, j, pos);
	if (j < a || b < i) return {inf, -1};
	if (a <= i && j <= b) return {mn[pos], st[pos]};
	int m = (i + j) / 2;
	return min(
		query(i, m, 2 * pos, a, b),
		query(m + 1, j, 2 * pos + 1, a, b)
	);
}

int n, p[MX], f[MX], a[MX], ind;
ll res, pre;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		f[p[i]] = i;
	}
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	build(1, n, 1);

	res = a[1];

	update(1, n, 1, 1, p[1] - 1, a[1]);
	for (int i = 2; i <= n; i++)
		update(1, n, 1, p[i], n, a[i]);
	res = min(res, query(1, n, 1, 1, n).fi);

	for (int i = 2; i + 1 <= n; i++) {
		update(1, n, 1, p[i], n, -a[i]);
		update(1, n, 1, 1, p[i] - 1, a[i]);
		res = min(res, query(1, n, 1, 1, n).fi);
	}

	cout << res << endl;

	return 0;
}