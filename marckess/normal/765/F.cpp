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

#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

const int MX = 100005, inf = 2000000005;
int n, a[MX], mp[MX], l[3*MX], r[3*MX], res[3*MX], m;
vi q[MX], c = {-1, inf};

struct ST {
	int st[4*MX];

	ST (int k) { init(k); }
	void init (int k) { fill(st, st+4*MX, k); }

	void update (int i, int j, int pos, int x, int k) {
		if (x < i || j < x) return;
		if (i == j) {
			st[pos] = k;
			return;
		}
		int m = (i+j)/2;
		update(i, m, pos*2, x, k);
		update(m+1, j, pos*2+1, x, k);
		st[pos] = max(st[pos*2], st[pos*2+1]);
	}

	int query (int i, int j, int pos, int a, int b) {
		if (b < i || j < a) return 0;
		if (a <= i && j <= b) return st[pos];
		int m = (i+j)/2;
		return max( query(i, m, pos*2, a, b), query(m+1, j, pos*2+1, a, b) );
	}

	void push (int i, int j, int pos) {
		if (i < j) {
			st[pos*2] = min(st[pos*2], st[pos]);
			st[pos*2+1] = min(st[pos*2+1], st[pos]);
			st[pos] = inf;
		}
	}

	void update (int i, int j, int pos, int a, int b, int k) {
		if (st[pos] != inf) push(i, j, pos);
		if (b < i || j < a) return;
		if (a <= i && j <= b) {
			st[pos] = min(st[pos], k);
			return;
		}
		int m = (i+j)/2;
		update(i, m, pos*2, a, b, k);
		update(m+1, j, pos*2+1, a, b, k);
	}

	int query (int i, int j, int pos, int x) {
		if (st[pos] != inf) push(i, j, pos);
		if (x < i || j < x) return inf;
		if (i == j) return st[pos];
		int m = (i+j)/2;
		return min( query(i, m, pos*2, x), query(m+1, j, pos*2+1, x) );
	}

}ind(0), mn(inf);

void obtMP () {
	sort(ALL(c));
	c.erase(unique(ALL(c)), c.end());
	for (int i = 1; i <= n; i++)
		mp[i] = find(c, a[i]);
}

void solve () {
	for (int i = 1; i <= n; i++) {
		int x = inf;
		while (1) {
			int y = ind.query(1, MX-1, 1, mp[i], find(c, x+1)-1);
			if (!y) break;
			mn.update(1, MX-1, 1, 1, y, a[y]-a[i]);
			x = (a[i]+a[y]-1)/2;
			if (x < a[i]) break;
		}
		ind.update(1, MX-1, 1, mp[i], i);
		for (int j : q[i]) {
			res[j] = min(res[j], mn.query(1, MX-1, 1, l[j]));
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		c.pb(a[i]);
	}
	obtMP();

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> l[i] >> r[i];
		res[i] = inf;
		q[r[i]].pb(i);
	}

	solve();

	ind.init(0);
	mn.init(inf);

	c = {-1, inf};
	for (int i = 1; i <= n; i++) {
		a[i] = inf/2-a[i];
		c.pb(a[i]);
	}
	obtMP();
	
	solve();

	for (int i = 0; i < m; i++)
		cout << res[i] << endl;
	return 0;

	return 0;
}