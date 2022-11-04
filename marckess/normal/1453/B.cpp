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

const int MX = 200005;
int n, a[MX];
ll s, res;

void update (int i, int k) {
	if (i) s -= abs(a[i] - a[i - 1]);
	if (i + 1 < n) s -= abs(a[i] - a[i + 1]);
	a[i] = k;
	if (i) s += abs(a[i] - a[i - 1]);
	if (i + 1 < n) s += abs(a[i] - a[i + 1]);
	res = min(res, s);
}

void solve () {
	cin >> n;
	s = 0;
	forn (i, n) {
		cin >> a[i];
		if (i) s += abs(a[i] - a[i - 1]);
	}
	res = s;
	forn (i, n) {
		int x = a[i];
		if (i) update(i, a[i - 1]);
		if (i + 1 < n) update(i, a[i + 1]);
		update(i, x);
	}
	
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}