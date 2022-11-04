#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 502, LMX = 61;
typedef bitset<MX> row;

void iden (row m[MX]) {
	for (int i = 0; i < MX; i++) {
		m[i].reset();
		m[i][i] = 1;
	}
}

void trans (row m[MX]) {
	bool temp;
	for (int i = 0; i < MX; i++)
		for (int j = i+1; j < MX; j++) {
			temp = m[i][j];
			m[i][j] = m[j][i];
			m[j][i] = temp;
		}
}

void mul (row a[MX], row b[MX], row c[MX]) {
	trans(b);
	for (int i = 0; i < MX; i++)
		for (int j = 0; j < MX; j++)
			c[i][j] = (a[i] & b[j]).any();
	trans(b);
}

void copy (row a[MX], row b[MX]) {
	for (int i = 0; i < MX; i++)
		a[i] = b[i];
}

row m0[MX], m1[MX];
row p[LMX][MX], b[LMX][MX];
row adj[MX], aux[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, m;
	cin >> n >> m;

	while (m--) {
		int u, v, t;

		cin >> u >> v >> t;
		u--, v--;
		
		if (t) b[0][u][v] = 1;
		else p[0][u][v] = 1;
	}

	for (int i = 1; i < LMX; i++) {
		mul(p[i-1], b[i-1], p[i]);
		mul(b[i-1], p[i-1], b[i]); 
	}

	ll res = 0;
	bool f = 0;
	iden(adj);
	
	for (int i = LMX - 1; i >= 0; i--) {
		if (f) mul(adj, b[i], aux);
		else mul(adj, p[i], aux);

		for (int j = 0; j < MX; j++)
			if (aux[0][j]) {
				copy(adj, aux);
				res |= (1ll << i);
				f ^= 1;
				break;
			}
	}

	if (res > 1e18) cout << -1 << endl;
	else cout << res << endl;

	return 0;
}