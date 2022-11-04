#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 55;
int n, a[MX];
vvi res;

bool valid () {
	forn (i, n - 1) if (a[i] > a[i + 1]) return 0;
	return 1;
}

void go () {
	forn (j, n) forn (i, j) if (a[i] - 1 == a[j]) {
		vi x, xx, y, z;
		
		int k = 0;
		while (k < i) {
			x.pb(a[k]);
			k++;
		}
		
		xx.pb(a[k]);
		k++;
		while (a[k] == a[k - 1] + 1) {
			xx.pb(a[k]);
			k++;
		}
		
		while (k < j) {
			y.pb(a[k]);
			k++;
		}
		y.pb(a[k]);
		k++;
		
		while (k < n) {
			z.pb(a[k]);
			k++;
		}
		
		k = 0;
		for (int r : z) a[k++] = r;
		for (int r : y) a[k++] = r;
		for (int r : xx) a[k++] = r;
		for (int r : x) a[k++] = r;
		
		res.pb({});
		if (x.size()) res.back().pb(x.size());
		if (xx.size()) res.back().pb(xx.size());
		if (y.size()) res.back().pb(y.size());
		if (z.size()) res.back().pb(z.size());
		
		return;
	}
}

void solve () {
	cin >> n;
	forn (i, n) cin >> a[i];
	
	while (!valid()) go();
	
	cout << res.size() << endl;
	for (vi &v : res) {
		cout << v.size() << " ";
		for (int x : v) cout << x << " ";
		cout << endl;
	}
}	

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--)
		solve();
	
	return 0;
}