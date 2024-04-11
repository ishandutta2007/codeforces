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

const int MX = 200005;

struct ST {
	ll st[4*MX], lz[4*MX], mn[4*MX];

	void init (int i, int j, int pos) {
		lz[pos] = 0;

		if (i == j) {
			st[pos] = i;
			mn[pos] = i;
			return;
		}

		int m = (i+j)/2;
		init(i, m, pos*2);
		init(m+1, j, pos*2+1);

		st[pos] = st[pos*2] + st[pos*2+1];
		mn[pos] = min(mn[pos*2], mn[pos*2+1]);
	}

	void upLazy (int i, int j, int pos) {
		st[pos] = lz[pos] * (j - i + 1);
		mn[pos] = lz[pos];
		
		if (i < j) {
			lz[pos*2] = lz[pos];
			lz[pos*2+1] = lz[pos];
		}
		
		lz[pos] = 0;
	}

	void update (int i, int j, int pos, int a, int b, int k) {
		if (lz[pos])
			upLazy(i, j, pos);

		if (j < a || b < i)
			return;

		if (a <= i && j <= b) {
			lz[pos] = k;
			upLazy(i, j, pos);
			return;
		}

		int m = (i+j)/2;
		update(i, m, pos*2, a, b, k);
		update(m+1, j, pos*2+1, a, b, k);

		st[pos] = st[pos*2] + st[pos*2+1];
		mn[pos] = min(mn[pos*2], mn[pos*2+1]);
	}

	int find (int i, int j, int pos, int k) {
		if (lz[pos])
			upLazy(i, j, pos);

		if (i == j) {
			if (st[pos] <= k)
				return i;
			return -1;
		}

		int m = (i+j)/2;
		if (mn[pos*2+1] <= k)
			return find(m+1, j, pos*2+1, k);
		return find(i, m, pos*2, k);
	}
}st;

vi adj[MX];
int n, a[MX], x;
ll res = 0, acu[MX];

void update (int i) {
	vi &v = adj[i];

	if (v.size() < 2)
		return;

	if (v[1] < n)
		st.update(1, n, 1, v[1] + 1, n, n + 1);

	int d = st.find(1, n, 1, v.back() - 1);
	if (v[0] + 1 <= min(d, v[1]));
		st.update(1, n, 1, v[0] + 1, min(d, v[1]), v.back());

	d = st.find(1, n, 1, v[v.size()-2] - 1);
	if (d >= 1)
		st.update(1, n, 1, 1, min(d, v[0]), v[v.size()-2]);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		a[x] = i;
	}

	for (int i = 1; i < MX; i++) {
		for (int j = i; j < MX; j += i)
			if (a[j])
				adj[i].push_back(a[j]);
		sort(ALL(adj[i]));
	}

	st.init(1, n, 1);

	for (int i = MX - 1; i >= 0; i--) {
		acu[i] = ll(n) * (n + 1) - st.st[1];
		update(i);
	}

	for (int i = 1; i < MX; i++) {
		if (acu[i] - acu[i-1]) {
			//cout << i << " " << acu[i] - acu[i-1] << endl;
		}
		res += i * (acu[i] - acu[i-1]);
	}

	cout << res << endl;

	return 0;
}