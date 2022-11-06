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

const int MX = 3005, inf = 1e9;
int n, a[MX], dp[MX][MX], acu[MX];

void solve () {
	cin >> n;
	forn (i, n)
		cin >> a[i];
	
	forn (i, n)
		forn (j, n)
			dp[i][j] = inf;
	
	dp[n - 1][n - 1] = 0;
	
	for (int i = n - 2; i >= 0; i--) {
		if (!a[i]) continue;
		
		int to = i + a[i];
		int act = inf;
		
		for (int j = i + 1; j <= to; j++)
			acu[j] = 0;
		
		for (int j = i + 1; j <= to; j++)
			if (a[j]) {
				acu[j + 1]++;
				acu[j + a[j] + 1]--;
			}
		
		for (int j = i + 2; j <= to; j++)
			acu[j] += acu[j - 1];
		
		for (int j = to; j > i; j--) {
			act = min(act, dp[j][to] + acu[j]);
			dp[i][j - 1] = act;
		}
	}
	
	cout << dp[0][0] << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}