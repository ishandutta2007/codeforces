#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 300005;

struct BIT {
	ll ft[MX];

	void init () {
		memset(ft, 0, sizeof(ft));
	}

	void update (int i, ll k) {
		while (i < MX) {
			ft[i] += k;
			i += i & -i;
		}
	}

	void update (int a, int b, ll k) {
		update(a, k);
		update(b+1, -k);
	}

	ll query (int i) {
		ll sum = 0;
		while (i) {
			sum += ft[i];
			i -= i & -i;
		}
		return sum;
	}
};

struct ST {
	int st[4*MX], pre[4*MX], suf[4*MX], a[MX];

	void init (int i, int j, int pos) {
		st[pos] = pre[pos] = suf[pos] = 0;

		if (i < j) {
			int m = (i+j)/2;
			init(i, m, pos*2);
			init(m+1, j, pos*2+1);
		} else {
			a[i] = 0;
		}
	}

	void update (int i, int j, int pos, int x, int k) {
		if (x < i || j < x)
			return;

		if (i == j) {
			a[i] = k;
			st[pos] = pre[pos] = suf[pos] = abs(k);
			return;
		}

		int m = (i+j)/2;
		update(i, m, pos*2, x, k);
		update(m+1, j, pos*2+1, x, k);

		if (a[m] && a[m+1] && a[m] >= a[m+1]) {
			st[pos] = max({st[pos*2], st[pos*2+1], suf[pos*2] + pre[pos*2+1]});
			pre[pos] = pre[pos*2] + pre[pos*2+1] * (pre[pos*2] == (m - i + 1));
			suf[pos] = suf[pos*2+1] + suf[pos*2] * (suf[pos*2+1] == (j - m));
		} else {
			st[pos] = max(st[pos*2], st[pos*2+1]);
			pre[pos] = pre[pos*2];
			suf[pos] = suf[pos*2+1];
		}
	}
};

int n, a[MX], q, l, r, d;
ll e;
BIT ft;
ST st;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ft.init();

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ft.update(i, a[i]-a[i-1]);
	}

	cin >> q;

	if (n == 1) {
		while (q--) {
			cin >> l >> r >> d;
			cout << 1 << endl;
		}
		return 0;
	}

	st.init(1, n-1, 1);

	for (int i = 1; i < n; i++) {
		e = a[i+1] - a[i];
		if (e)
			st.update(1, n-1, 1, i, e / abs(e));
		else
			st.update(1, n-1, 1, i, 0);
	}

	while (q--) {
		cin >> l >> r >> d;
		ft.update(l, r, d);

		if (l > 1) {
			e = ft.query(l) - ft.query(l-1);
			if (e)
				st.update(1, n-1, 1, l-1, e/abs(e));
			else
				st.update(1, n-1, 1, l-1, 0);
		}

		if (r < n) {
			e = ft.query(r+1) - ft.query(r);
			if (e)
				st.update(1, n-1, 1, r, e/abs(e));
			else
				st.update(1, n-1, 1, r, 0);
		}

		cout << st.st[1] + 1 << endl;
	}

	return 0;
}