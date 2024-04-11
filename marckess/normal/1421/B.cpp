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

const int MX = 205;
int n;
char c[MX][MX];

void solve () {
	cin >> n;
	
	forn (i, n) cin >> c[i];
	
	vii res;
	
	if (c[1][0] == c[0][1]) {
		if (c[n - 1][n - 2] == c[1][0])
			res.emplace_back(n - 1, n - 2);
		if (c[n - 2][n - 1] == c[1][0])
			res.emplace_back(n - 2, n - 1);	
	} else if (c[n - 1][n - 2] == c[n - 2][n - 1]) {
		if (c[1][0] == c[n - 1][n - 2])
			res.emplace_back(1, 0);
		if (c[0][1] == c[n - 2][n - 1])
			res.emplace_back(0, 1);
	} else {
		if (c[0][1] != '1')
			res.emplace_back(0, 1);
		if (c[1][0] != '1')
			res.emplace_back(1, 0);
		if (c[n - 1][n - 2] != '0')
			res.emplace_back(n - 1, n - 2);
		if (c[n - 2][n - 1] != '0')
			res.emplace_back(n - 2, n - 1);
	}
	
	cout << res.size() << endl;
	for (auto r : res)
		cout << r.fi + 1 << " " << r.se + 1 << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}