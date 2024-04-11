#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

int n, a, b, c, r;
string s, res;

int solve () {
	cin >> n >> a >> b >> c >> s;
	res = string(n, char(0));

	r = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'R' && b > 0) {
			res[i] = 'P';
			b--;
			r++;
		}
		if (s[i] == 'P' && c > 0) {
			res[i] = 'S';
			c--;
			r++;
		}
		if (s[i] == 'S' && a > 0) {
			res[i] = 'R';
			a--;
			r++;
		}
	}

	if (2 * r < n) {
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;
	for (char t : res) {
		if (t) {
			cout << t;
		} else if (a) {
			cout << 'R';
			a--;
		} else if (b) {
			cout << 'P';
			b--;
		} else {
			cout << 'S';
			c--;
		}
	}
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}