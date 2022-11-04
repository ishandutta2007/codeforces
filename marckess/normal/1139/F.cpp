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

#include <bits/extc++.h>
using namespace __gnu_pbds;

typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MX = 100005;
int n, m, p[MX], s[MX], b[MX], inc[MX], pref[MX], res[MX], qn[MX], qs[MX], qm[MX];
vi c;
ordered_set pos[MX], neg[MX];

void insert (int i, ii k, ordered_set ft[]) {
	while (i < MX) {
		ft[i].insert(k);
		i += i & -i;
	}
}

void erase (int i, ii k, ordered_set ft[]) {
	while (i < MX) {
		ft[i].erase(k);
		i += i & -i;
	}
}

int query (int i, int k, ordered_set ft[]) {
	int res = 0;
	while (i) {
		res += ft[i].order_of_key(ii(k, MX));
		i -= i & -i;
	}
	return res;
}

int query (int i, int j, int k, ordered_set ft[]) {
	return query(j, k, ft) - query(i - 1, k, ft);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	
	forn (i, n) cin >> p[i];
	forn (i, n) cin >> s[i];
	forn (i, n) {
		cin >> b[i];
		c.pb(b[i]);
	}
	
	forn (i, m) cin >> inc[i];
	forn (i, m) cin >> pref[i];

	iota(qn, qn + n, 0);
	sort(qn, qn + n, [&] (int i, int j) {
		return p[i] < p[j];
	});

	iota(qs, qs + n, 0);
	sort(qs, qs + n, [&] (int i, int j) {
		return s[i] < s[j];
	});

	iota(qm, qm + m, 0);
	sort(qm, qm + m, [&] (int i, int j) {
		return inc[i] < inc[j];
	});

	sort(all(c));
	c.erase(unique(all(c)), c.end());

	int st, _st = 0, en, _en = 0;
	forn (_i, m) {
		int i = qm[_i];

		while (_st < n && p[st = qn[_st]] <= inc[i]) {
			int k = upper_bound(all(c), b[st]) - c.begin();

			insert(k, {p[st] + b[st], st}, pos);
			insert(k, {p[st] - b[st], st}, neg);

			_st++;
		}

		while (_en < n && s[en = qs[_en]] < inc[i]) {
			int k = upper_bound(all(c), b[en]) - c.begin();

			erase(k, {p[en] + b[en], en}, pos);
			erase(k, {p[en] - b[en], en}, neg);

			_en++;
		}

		int k = upper_bound(all(c), pref[i]) - c.begin();

		if (k < c.size()) res[i] += query(k + 1, c.size(), inc[i] + pref[i], pos);
		if (k) res[i] += query(k, inc[i] - pref[i], neg);
	}

	forn (i, m) cout << res[i] << " ";
	cout << endl;

	return 0;
}