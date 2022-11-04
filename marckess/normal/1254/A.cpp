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

const int MX = 105;
int n, m, k, cn;
char a[MX][MX], res[MX][MX];
string s = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890";
string t;

void solve () {
	cin >> n >> m >> k;
	cn = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'R')
				cn++;
		}

	t.clear();
	for (int i = 0; i < cn % k; i++)
		for (int j = 0; j < cn / k + 1; j++)
			t.pb(s[i]);

	for (int i = 0, off = cn % k; i < k - (cn % k); i++)
		for (int j = 0; j < cn / k; j++)
			t.pb(s[off+i]);
	t.pb(t.back());

	for (int i = 0, l = 0; i < n; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < m; j++) {
				res[i][j] = t[l];
				if (a[i][j] == 'R')
					l++;
			}
		} else {
			for (int j = m - 1; j >= 0; j--) {
				res[i][j] = t[l];
				if (a[i][j] == 'R')
					l++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << res[i][j];
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