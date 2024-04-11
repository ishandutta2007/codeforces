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

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		vi cn(256);
		string s;
		cin >> s;

		for (char c : s)
			cn[c]++;

		int x = min({cn['L'], cn['R']});
		int y = min(cn['U'], cn['D']);
		if (!x) y = min(y, 1);
		if (!y) x = min(x, 1);

		cout << 2 * (x + y) << endl;
		forn (i, x) cout << 'L';
		forn (i, y) cout << 'U';
		forn (i, x) cout << 'R';
		forn (i, y) cout << 'D';
		cout << endl;
	}

	return 0;
}