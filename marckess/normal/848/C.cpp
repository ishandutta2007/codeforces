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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 100005, SQ = 316;
int n, q, a[MX], blo[MX];
int ft[SQ+5][MX];
ll sum[MX];
set<int> pos[MX];

void update (int i, int k, ll ft[]) {
	if (!i) return;
	while (i < MX) {
		ft[i] += k;
		i += i & -i;
	}
}

void update (int i, int k, int ft[]) {
	if (!i) return;
	while (i < MX) {
		ft[i] += k;
		i += i & -i;
	}
}

ll query (int i, ll ft[]) {
	ll s = 0;
	while (i) {
		s += ft[i];
		i -= i & -i;
	}
	return s;
}

int query (int i, int ft[]) {
	int s = 0;
	while (i) {
		s += ft[i];
		i -= i & -i;
	}
	return s;
}

ll query (int a, int b, ll ft[]) {
	return query(b, ft) - query(a - 1, ft);
}

int query (int a, int b, int ft[]) {
	return query(b, ft) - query(a - 1, ft);
}

void add (int i) {
	pos[a[i]].insert(i);
	auto it = pos[a[i]].find(i);

	it--; int ant = *it;
	it++, it++; int sig = *it;

	update(ant, (i - ant) - (sig - ant), sum);
	update(i, sig - i, sum);

	update(ant, (sig - ant) - (i - ant), ft[blo[ant]]);
	update(sig, -(sig - ant), ft[blo[ant]]);
	update(i, i - ant, ft[blo[ant]]);

	update(i, -(sig - i), ft[blo[i]]);
	update(sig, sig - i, ft[blo[i]]);
}

void remove (int i) {
	pos[a[i]].erase(i);
	auto it = pos[a[i]].upper_bound(i);

	int sig = *it;
	it--; int ant = *it;

	update(ant, (sig - ant) - (i - ant), sum);
	update(i, -(sig - i), sum);

	update(ant, (i - ant) - (sig - ant), ft[blo[ant]]);
	update(sig, sig - ant, ft[blo[ant]]);
	update(i, -(i - ant), ft[blo[ant]]);

	update(i, sig - i, ft[blo[i]]);
	update(sig, -(sig - i), ft[blo[i]]);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;
	forn (i, n) pos[i+1].insert(0), pos[i+1].insert(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		blo[i] = i / SQ;
		add(i);
	}

	while (q--) {
		int op, x, y;
		cin >> op >> x >> y;

		if (op == 1) {
			remove(x);
			a[x] = y;
			add(x);
		} else {
			ll res = query(x, y, sum);

			for (int i = y; i >= x && blo[i] == blo[y]; i--) {
				int sig = *pos[a[i]].upper_bound(i);
				if (sig > y)
					res -= sig - i;
			}

			if (blo[x] != blo[y]) {
				for (int i = x; blo[i] == blo[x]; i++) {
					int sig = *pos[a[i]].upper_bound(i);
					if (sig > y)
						res -= sig - i;
				}
			}

			for (int i = blo[x] + 1; i < blo[y]; i++)
				res += query(y, ft[i]);

			cout << res << endl;
		}
	}

	return 0;
}