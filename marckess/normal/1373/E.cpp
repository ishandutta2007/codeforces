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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 155;
int mem[MX][MX][10];
int n, k, acu[10][10];

int dp (int i, int s) {
	if (!i || s < 0) return 0;

	int &res = mem[i][s][k];
	if (res != -1) return res;

	forn (j, 10)
		if (dp(i - 1, s - (k + 1) * j))
			return res = 1;

	forn (j, 10) forn (ini, 10) {
		int x = min(k + 1, 10 - ini);
		int y = k + 1 - x;
		if (j == 9 && y) continue;

		if (s == x * j + y * (j + 1) + 9 * (i - 1) * x + acu[k][ini]) return res = 1;
	}

	return res = 0;
}

void rec (int i, int s, int f) {
	forn (j, 10)
		if (dp(i - 1, s - (k + 1) * j)) {
			if (f || j) cout << j;
			return rec(i - 1, s - (k + 1) * j, f || j);
		}

	forn (j, 10) forn (ini, 10) {
		int x = min(k + 1, 10 - ini);
		int y = k + 1 - x;
		if (j == 9 && y) continue;

		if (s == x * j + y * (j + 1) + 9 * (i - 1) * x + acu[k][ini]) {
			if (f || j) cout << j;
			while (--i) cout << 9;
			cout << ini;
			return;
		}
	}
}

void solve () {
	cin >> n >> k;

	if (dp(18, n)) {
		rec(18, n, 0);
		cout << endl;
		return;
	}

	cout << -1 << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(mem, -1, sizeof(mem));

	forn (i, 10) forn (j, 10) forn (k, i + 1) acu[i][j] += (j + k) % 10;

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}