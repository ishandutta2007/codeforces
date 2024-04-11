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
int n;
char a[MX][MX];
queue<ii> q;

void solve () {
	cin >> n;
	forn (i, n) cin >> a[i];

	for (int i = 0; i < n; i++) {
		if (a[n - 1][i] == '1') {
			q.emplace(n - 1, i);
			a[n - 1][i] = '0'; 
		}
		if (a[i][n - 1] == '1') {
			q.emplace(i, n - 1);
			a[i][n - 1] = '0';
		}
	}

	while (q.size()) {
		int i = q.front().fi;
		int j = q.front().se;
		q.pop();

		if (i && a[i - 1][j] == '1') {
			a[i - 1][j] = '0';
			q.emplace(i - 1, j);
		}

		if (j && a[i][j - 1] == '1') {
			a[i][j - 1] = '0';
			q.emplace(i, j - 1);
		}
	}

	forn (i, n) forn (j, n) if (a[i][j] == '1') {
		cout << "NO" << endl;
		return;
	}

	cout << "YES" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}