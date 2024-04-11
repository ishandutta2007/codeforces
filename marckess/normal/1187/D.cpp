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

const int MX = 300005;
int n, ft[MX];
queue<int> q[MX];
vi a, b;

void update (int i, int k) {
	while (i) {
		ft[i] = max(ft[i], k);
		i -= i & -i;
	}
}

int query (int i) {
	int s = 0;
	while (i <= n) {
		s = max(s, ft[i]);
		i += i & -i;
	}
	return s;
}

void solve () {
	cin >> n;
	a.resize(n);
	b.resize(n);

	for (int i = 1; i <= n; i++) {
		while (q[i].size()) q[i].pop();
		ft[i] = 0;	
	}

	forn (i, n) {
		cin >> a[i];
		q[a[i]].push(i);
	}
	forn (i, n) cin >> b[i];

	forn (i, n) {
		if (q[b[i]].empty() || query(b[i]) > q[b[i]].front()) {
			cout << "NO" << endl;
			return;
		}

		update(b[i], q[b[i]].front());
		q[b[i]].pop();
	}

	cout << "YES" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}