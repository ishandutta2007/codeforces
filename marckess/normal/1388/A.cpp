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

int n;
vi p = {2, 3, 5, 7, 11, 13, 17, 19}, np;

void solve () {
	cin >> n;

	forn (i, np.size()) forn (j, i) forn (k, j) {
		int r = n - np[i] - np[j] - np[k];
		if (r > 0 && r != np[i] && r != np[j] && r != np[k]) {
			cout << "YES" << endl;
			cout << np[i] << " " << np[j] << " " << np[k] << " " << r << endl;
			return;
		}
	}

	cout << "NO" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	forn (i, p.size()) forn (j, i) np.pb(p[i] * p[j]);

	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}