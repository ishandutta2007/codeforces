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

int n, m, a, b, g, x, y, z, h[3005][3005];
deque<ii> fil, col[3005];

void insert (int x, int i, deque<ii> &q) {
	while (q.size() && q.back().fi > x) q.pop_back();
	q.pb(x, i);
}

int query (int i, deque<ii> &q) {
	while (q.front().se <= i) q.pop_front();
	return q.front().fi;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> a >> b >> g >> x >> y >> z;
	forn (i, n) forn(j, m) {
		h[i][j] = g;
		g = (1ll * g * x + y) % z;
	}

	ll res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			insert(h[i][j], i, col[j]);
			insert(query(i - a, col[j]), j, fil);
			if (i - a >= -1 && j - b >= -1)
				res += query(j - b, fil);
		}

		while (fil.size()) fil.pop_back();
	}

	cout << res << endl;

	return 0;
}