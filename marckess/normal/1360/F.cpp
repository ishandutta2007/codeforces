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

const int MX = 55;
int n, m;
string s[MX], res;

bool valid (string &res) {
	forn (i, n) {
		int cn = 0;
		forn (j, m)
			cn += res[j] != s[i][j];
		if (cn > 1) return 0;
	}

	return 1;
}

void solve () {
	cin >> n >> m;
	forn (i, n) cin >> s[i];

	res = s[n - 1];

	for (int j = 0; j < m; j++)
		for (int k = 0; k < n; k++) {
			res[j] = s[k][j];
			if (valid(res)) {
				cout << res << endl;
				return;
			}
		}

	cout << -1 << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}