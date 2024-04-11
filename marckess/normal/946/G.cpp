#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 400010;

struct ST {
	int st[4*MX], p[MX];

	ST () { build(1, MX-1, 1); }

	void build (int i, int j, int pos) {
		st[pos] = 0;

		if (i == j) {
			p[i] = pos;
			return;
		}

		int m = (i+j)/2;
		build(i, m, pos*2);
		build(m+1, j, pos*2+1);
	}

	void update (int x, int k) {
		int pos = p[x];
		st[pos] = k;
		pos /= 2;

		while (pos) {
			st[pos] = max(st[pos*2], st[pos*2+1]);
			pos /= 2;
		}
	}

	int leq (int i, int j, int pos, int x) {
		if (i > x) return 0;
		if (j <= x) return st[pos];

		int m = (i + j) / 2;
		return max( leq(i, m, pos*2, x), leq(m+1, j, pos*2+1, x) );
	}

	int geq (int i, int j, int pos, int x) {
		if (i >= x) return st[pos];
		if (j < x) return 0;

		int m = (i + j) / 2;
		return max( geq(i, m, pos*2, x), geq(m+1, j, pos*2+1, x) );
	}
}st;

int n, a[MX], res[MX];
vi c;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] -= i;
		c.pb(a[i]);
		c.pb(a[i]+1);
	}

	sort(ALL(c));
	c.erase(unique(ALL(c)), c.end());

	for (int i = 0; i < n; i++)
		a[i] = lower_bound(ALL(c), a[i]) - c.begin() + 1;

	for (int i = 1; i < n; i++) {
		st.update(a[i-1], 1 + st.leq(1, MX-1, 1, a[i-1]));
		res[i] = st.leq(1, MX-1, 1, a[i-1]);
	}

	st.build(1, MX-1, 1);

	for (int i = n-2; i >= 0; i--) {
		st.update(a[i+1]+1, 1 + st.geq(1, MX-1, 1, a[i+1]+1));
		if (i-1>0)res[i] += st.geq(1, MX-1, 1, a[i-1]);
	}

	cout << n - 1 - max(*max_element(res, res+n), st.geq(1, MX-1, 1, 1)) << endl;

	return 0;
}