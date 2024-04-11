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
typedef double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const ll inf = 1e18;
const int MX = 500005;
int n, a[MX], p[MX], m, b[MX], f[MX];
ll ft[MX], x[MX], sum, mn[MX];

void update (int i, ll k) {
	while (i < MX) {
		ft[i] += k;
		i += i & -i;
	}
}

ll query (int i) {
	ll s = 0;
	while (i) {
		s += ft[i];
		i -= i & -i;
	}
	return s;
}

ll query (int a, int b) {
	return query(b) - query(a - 1);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	forn (i, n) cin >> a[i + 1];
	forn (i, n) {
		cin >> p[i + 1];
		if (p[i + 1] < 0)
			sum += p[i + 1];
	}

	cin >> m;
	forn (i, m) {
		cin >> b[i + 1];
		f[b[i + 1]] = i + 1;
	}

	int j = 1;
	forn (i, n)
		if (j <= m && a[i + 1] == b[j])
			j++;
	
	if (j <= m) {
		cout << "NO" << endl;
		return 0;
	}

	for (int i = n; i; i--) {
		if (p[i] < 0) x[i] -= p[i];
		else update(a[i], p[i]);

		if (f[a[i]])
			x[i] -= query(b[f[a[i]] - 1] + 1, a[i]);
	}

	fill(mn, mn + MX, inf);

	mn[m + 1] = 0;
	for (int i = n; i; i--)
		if (f[a[i]])
			mn[f[a[i]]] = min(mn[f[a[i]]], x[i] + mn[f[a[i]] + 1]);

	cout << "YES" << endl << mn[1] + sum + query(n) << endl;

	return 0;
}