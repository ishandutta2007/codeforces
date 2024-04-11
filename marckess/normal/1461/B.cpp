#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 505;
int n, m;
int acu[MX][MX];
char a[MX][MX];

int sum (int i, int a, int b) {
	if (a) return acu[i][b] - acu[i][a - 1];
	return acu[i][b];
}

void solve () {
	cin >> n >> m;
	
	forn (i, n) {
		forn (j, m) {
			cin >> a[i][j];
			acu[i][j] = a[i][j] == '*';
			if (j)
				acu[i][j] += acu[i][j - 1];
		}
	}
	
	int res = 0;
	
	forn (i, n)
		forn (j, m)
			for (int k = 0; i + k < n && j - k >= 0 && j + k < m && sum(i + k, j - k, j + k) == 2 * k + 1; k++, res++);
	
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