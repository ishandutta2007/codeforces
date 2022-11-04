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

const int MX = 100005;
int n, k;
ll x[MX], x2[MX], y[MX], y2[MX], a, b, c, d;
bitset<MX> exi;
ll res = numeric_limits<ll>::max();
int qa[MX], qb[MX], qc[MX], qd[MX];

ll obtRes (vi &v) {
	a = 0, b = 0, c = 0, d = 0;

	for (int z : v) {
		if (!z) {
			while (!exi[qa[a]]) a++;
			exi[qa[a]] = 0;
		} else if (z == 1) {
			while (!exi[qb[b]]) b++;
			exi[qb[b]] = 0;
		} else if (z == 2) {
			while (!exi[qc[c]]) c++;
			exi[qc[c]] = 0;
		} else {
			while (!exi[qd[d]]) d++;
			exi[qd[d]] = 0;
		}
	}

	while (!exi[qa[a]]) a++;
	while (!exi[qb[b]]) b++;
	while (!exi[qc[c]]) c++;
	while (!exi[qd[d]]) d++;

	ll res = max(1ll, ll((x2[qc[c]] - x[qa[a]] + 1) / 2)) * max(1ll, ((y2[qd[d]] - y[qb[b]] + 1) / 2));

	while (a >= 0) { exi[qa[a]] = 1; a--; }
	while (b >= 0) { exi[qb[b]] = 1; b--; }
	while (c >= 0) { exi[qc[c]] = 1; c--; }
	while (d >= 0) { exi[qd[d]] = 1; d--; }

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	exi.set();

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c >> d;
		x[i] = x2[i] = (c + a);
		y[i] = y2[i] = (d + b);
	}

	iota(qa, qa+n, 0);
	sort(qa, qa+n, [&] (int i, int j) {
		return x[i] < x[j];
	});

	iota(qb, qb+n, 0);
	sort(qb, qb+n, [&] (int i, int j) {
		return y[i] < y[j];
	});

	iota(qc, qc+n, 0);
	sort(qc, qc+n, [&] (int i, int j) {
		return x2[i] > x2[j];
	});

	iota(qd, qd+n, 0);
	sort(qd, qd+n, [&] (int i, int j) {
		return y2[i] > y2[j];
	});

	for (int i = 0; i <= k; i++)
	for (int j = 0; j <= k; j++)
	for (int l = 0; l <= k; l++)
	for (int m = 0; m <= k; m++) {
		if (i + j + l + m != k) continue;

		vi v;
		for (int z = 0; z < i; z++) v.push_back(0);
		for (int z = 0; z < j; z++) v.push_back(1);
		for (int z = 0; z < l; z++) v.push_back(2);
		for (int z = 0; z < m; z++) v.push_back(3);

		do {
			res = min(res, obtRes(v));
		} while (next_permutation(ALL(v)));
	}

	cout << max(1ll, res) << endl;

	return 0;
}