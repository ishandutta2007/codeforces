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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 300005;
int n, m, ft[MX], mn[MX], mx[MX], a[MX], ant[MX], q[MX];
vi pos[MX];

void update (int i, int k) {
	while (i < MX) {
		ft[i] += k;
		i += i & -i;
	}
}

int query (int i) {
	int s = 0;
	while (i) {
		s += ft[i];
		i -= i & -i;
	}
	return s;
}

int query (int a, int b) {
	return query(b) - query(a - 1);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		mn[i] = mx[i] = i;

	for (int i = 1; i <= m; i++) {
		cin >> a[i];
		mn[a[i]] = 1;
		
		if (pos[a[i]].size()) 
			q[i] = pos[a[i]].back();

		pos[a[i]].pb(i);
	}

	for (int i = n; i > 0; i--)
		if (pos[i].size()) {
			mx[i] = max(mx[i], query(pos[i][0]) + i);
			update(pos[i][0], 1);
		} else {
			mx[i] = max(mx[i], query(m) + i);
		}

	memset(ft, 0, sizeof(ft));
	for (int i = 1; i <= m; i++) {
		int x = a[i];

		if (ant[x])
			update(ant[x], -1);
		update(i, 1);
		ant[x] = i;

		if (q[i]) {
			mx[x] = max(mx[x], query(q[i], i));
		}
	}

	for (int i = 1; i <= n; i++)
		if (pos[i].size())
			mx[i] = max(mx[i], query(pos[i].back(), m));

	for (int i = 1; i <= n; i++)
		cout << mn[i] << " " << mx[i] << endl;

	return 0;
}