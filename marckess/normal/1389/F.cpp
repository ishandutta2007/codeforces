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

const int MX = 400005;

struct ST {
	int st[4 * MX], lz[4 * MX];

	ST () {
		memset(st, 0, sizeof(st));
		memset(lz, 0, sizeof(lz));
	}

	void push (int i, int j, int pos) {
		if (i < j) {
			lz[pos * 2] += lz[pos];
			lz[pos * 2 + 1] += lz[pos];
		}

		st[pos] += lz[pos];
		lz[pos] = 0;
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
		update(i, m, pos * 2, a, b, k);
		update(m + 1, j, pos * 2 + 1, a, b, k);

		st[pos] = max(st[pos * 2], st[pos * 2 + 1]);
	}

}st[2];

int n, l[MX], r[MX], t[MX];
vi c = {-1, int(2e9)};
vi ini[MX];

int find (vi &v, int x) {
	return lower_bound(all(v), x) - v.begin();
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, n) {
		cin >> l[i] >> r[i] >> t[i];
		t[i]--;
		c.pb(l[i]);
		c.pb(r[i]);
	}

	sort(all(c));
	c.erase(unique(all(c)), c.end());

	forn (i, n) {
		l[i] = find(c, l[i]);
		r[i] = find(c, r[i]);
		ini[l[i]].pb(i);
	}

	int m = c.size();
	for (int i = m - 1; i > 0; i--) {
		int x = st[0].st[1];
		int y = st[1].st[1];
		
		st[0].update(1, m, 1, i, i, y);
		st[1].update(1, m, 1, i, i, x);

		for (int j : ini[i])
			st[t[j]].update(1, m, 1, r[j], m, 1);
	}

	cout << max(st[0].st[1], st[1].st[1]) << endl;

	return 0;
}