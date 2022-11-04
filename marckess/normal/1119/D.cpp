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

const int MX = 100005;
int n, q;
ll a[MX], l, r, c[MX], res[MX], o[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a+n);
	
	for (int i = 0; i < n; i++)
		a[i] = a[i+1] - a[i];
	a[n-1] = ll(1e18)+5;
	sort(a, a+n);

	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> l >> r;
		c[i] = r - l + 1;
	}

	iota(o, o+q, 0);
	sort(o, o+q, [&] (int i, int j) {
		return c[i] < c[j];
	});

	ll acu = 0, ant = 0;
	for (int i = 0, j = 0; i < q; i++) {
		int u = o[i];

		while (a[j] < c[u]) {
			acu += a[j] - ant;
			j++;
		}

		acu += ll(n - j) * (c[u] - ant);

		res[u] = acu;
		ant = c[u];
	}

	for (int i = 0; i < q; i++)
		cout << res[i] << " ";
	cout << endl;

	return 0;
}