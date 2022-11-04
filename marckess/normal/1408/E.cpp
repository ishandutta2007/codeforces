#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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

const int MX = 100005;
int n, m, a[MX], b[MX];
int u[2 * MX], v[2 * MX], w[2 * MX], q[2 * MX], sz;
int p[2 * MX];
ll res;

int parent (int a) {
	return a == p[a] ? a : p[a] = parent(p[a]);
}

bool join (int a, int b) {
	a = parent(a), b = parent(b);
	if (a == b) return 0;
	p[a] = b;
	return 1;
}

void solve () {
	cin >> m >> n;

	forn (i, m) cin >> a[i];
	forn (i, n) cin >> b[i];

	forn (i, m) {
		int s;
		cin >> s;
		while (s--) {
			int x;
			cin >> x;
			x--;
			u[sz] = x;
			v[sz] = n + i;
			w[sz] = a[i] + b[x];
			sz++;
		}
	}

	iota(q, q + sz, 0);
	sort(q, q + sz, [&] (int i, int j) {
		return w[i] > w[j];
	});	

	iota(p, p + 2 * MX, 0);

	forn (_, sz) {
		int i = q[_];
		if (!join(u[i], v[i]))
			res += w[i];
	}

	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t = 1;
	//cin >> t;
	while (t--)	
		solve();

	return 0;
}