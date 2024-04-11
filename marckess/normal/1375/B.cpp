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

const int MX = 305;
int n, m, a[MX][MX];
int mx[] = {1, -1, 0, 0};
int my[] = {0, 0, 1, -1};

bool valid (int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m; 
}

void solve () {
	cin >> n >> m;

	forn (i, n) forn (j, m) cin >> a[i][j];

	forn (i, n) forn (j, m) {
		int p = 0;
		forn (l, 4) if (valid(i + mx[l], j + my[l])) p++;

		if (a[i][j] > p) {
			cout << "NO" << endl;
			return;
		}

		a[i][j] = p;
	}

	cout << "YES" << endl;
	forn (i, n) {
		forn (j, m) cout << a[i][j] << " ";
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