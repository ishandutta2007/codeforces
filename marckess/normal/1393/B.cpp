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
int n, a[MX], cn[MX], t, f, q;

void upd (int k, int x) {
	t -= cn[k] / 2;
	f -= cn[k] / 4;
	cn[k] += x;
	t += cn[k] / 2;
	f += cn[k] / 4;
}

void solve () {
	cin >> n;
	
	forn (i, n) {
		cin >> a[i];
		upd(a[i], 1);
	}

	cin >> q;
	while (q--) {
		char c;
		int x;
		cin >> c >> x;

		if (c == '+') upd(x, 1);
		else upd(x, -1);

		if (t >= 4 && f >= 1) cout << "YES" << endl;
		else cout << "NO" << endl;
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