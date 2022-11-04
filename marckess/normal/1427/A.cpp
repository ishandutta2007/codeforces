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

int n;
vi x, y;

void solve () {
	cin >> n;
	x.clear(), y.clear();
	int a = 0, b = 0, c = 0;
	
	while (n--) {
		int in;
		cin >> in;
		if (in == 0) {
			c++;
		} else if (in < 0) {
			x.pb(in);
			a += in;
		} else {
			y.pb(in);
			b += in;
		}
	}
	
	a = abs(a);
	if (a == b) cout << "NO" << endl;
	else if (a > b) {
		cout << "YES" << endl;
		for (int r : x) cout << r << " ";
		for (int r : y) cout << r << " ";
		while (c--) cout << 0 << " ";
		cout << endl;
	} else {
		cout << "YES" << endl;
		for (int r : y) cout << r << " ";
		for (int r : x) cout << r << " ";
		while (c--) cout << 0 << " ";
		cout << endl;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}