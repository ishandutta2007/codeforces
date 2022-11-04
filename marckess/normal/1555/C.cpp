
// Problem : C. Coin Rows
// Contest : Codeforces - Educational Codeforces Round 112 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1555/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, a[2][MX], acu[2][MX];

void solve () {
	cin >> n;
	forn (i, 2)
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			acu[i][j] = acu[i][j - 1] + a[i][j];
		}
	
	int res = 2e9 + 5;
	for (int i = 1; i <= n; i++)
		res = min(res, max(acu[1][i - 1], acu[0][n] - acu[0][i]));
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}