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
int p, n, a[MX], ini;
vi res;

bool esPos (ll x) {
	for (int i = 0, j = 0; i < n; i++) {
		while (j < n && a[j] <= x + i) j++;
		if ((j - i) % p == 0) return 0;
	}
	return 1;
}

void solve () {
	cin >> n >> p;
	forn (i, n) cin >> a[i];
	sort(a, a + n);

	forn (i, n) ini = max(ini, a[i] - i);

	ll i = ini, j = ini + n, rep = 32;
	while (rep--) {
		ll m = (i + j + 1) / 2;
		if (esPos(m)) i = m;
		else j = m;
	}

	if (esPos(i)) {
		while (ini <= i) {
			res.pb(ini);
			ini++;
		}
	}

	cout << res.size() << endl;
	for (int r : res)
		cout << r << " ";
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--)
		solve();	

	return 0;
}