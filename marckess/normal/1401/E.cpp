#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1000000;
int n, m;
int ft[MX + 5];
vi ini[MX + 5];
vi fin[MX + 5];
vii in[MX + 5];
ll res = 1;

void update (int i, int k) {
	while (i <= MX) {
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
	if (a) return query(b) - query(a - 1);
	return query(b);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	
	forn (i, n) {
		int y, lx, rx;
		cin >> y >> lx >> rx;

		ini[lx].pb(y);
		fin[rx].pb(y);

		if (lx == 0 && rx == MX)
			res++;
	}

	forn (i, m) {
		int x, ly, ry;
		cin >> x >> ly >> ry;

		in[x].emplace_back(ly, ry);

		if (ly == 0 && ry == MX)
			res++;
	}

	forn (i, MX) {
		for (int j : ini[i])
			update(j, 1);

		for (ii &p : in[i])
			res += query(p.fi, p.se);

		for (int j : fin[i])
			update(j, -1);
	}

	cout << res << endl;
	
	return 0;
}