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
int n, a[MX], mem[MX][2 * MX + 5];

int dp (int i, int j) {
	if (i == n) return 0;
	if (j > 2 * n) return 1e9;
	
	int &res = mem[i][j];
	if (res != -1) return res;
	return res = min(
		dp(i, j + 1),
		dp(i + 1, j + 1) + abs(a[i] - j)
	);
}	

void solve () {
	cin >> n;
	forn (i, n) cin >> a[i];
	sort(a, a + n);
	forn (i, n) forn (j, 2 * n + 5) mem[i][j] = -1;
	cout << dp(0, 1) << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}