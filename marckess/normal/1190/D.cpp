#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 200005;
int n, x[MX], y[MX], ft[MX];
vi c, pos[MX];

void update (int i, int k) {
	while (i < MX) {
		ft[i] += k;
		i += i & -i;
	}
}

int query(int i) {
	int s = 0;
	while (i) {
		s += ft[i];
		i -= i & -i;
	}
	return s;
}

int query(int a, int b) {
	if (a > b) return 0;
	if (!a) return query(b);
	return query(b) - query(a - 1);
}

void domp(int a[]) {
	for (int i = 0; i < n; i++)
		c.pb(a[i]);
	sort(all(c));
	c.erase(unique(all(c)), c.end());
	for (int i = 0; i < n; i++)
		a[i] = lower_bound(all(c), a[i]) - c.begin() + 1;
}

set<int> st;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];

	domp(x);
	c.clear();
	domp(y);

	for (int i = 0; i < n; i++)
		pos[y[i]].pb(x[i]);

	ll res = 0;
	for (int i = MX - 1; i > 0; i--) {
		sort(all(pos[i]));
		for (int j = 0; j < pos[i].size(); j++) {
			res += ll(query(pos[i][j] - 1) + 1) * ll(query(pos[i][j] + 1, (j + 1 < pos[i].size() ? pos[i][j+1] : MX) - 1) + 1);
			if (!st.count(pos[i][j])) {
				update(pos[i][j], 1);
				st.insert(pos[i][j]);
			} 
		}
	}
	cout << res << endl;

	return 0;
}