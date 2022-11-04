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

const int MX = 100005;
int r, n, t[MX], x[MX], y[MX], dp[MX], mx[MX], res;

void solve () {
	cin >> r >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> x[i] >> y[i];
		dp[i] = -1e9;	
	}
	x[0] = y[0] = 1;
	
	for (int i = 1; i <= n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (t[i] - t[j] > 2 * (r - 1)) {
				dp[i] = max(dp[i], mx[j] + 1);
				break;
			} 
			
			int dx = abs(x[i] - x[j]);
			int dy = abs(y[i] - y[j]);
			
			if (dx + dy <= t[i] - t[j]) dp[i] = max(dp[i], dp[j] + 1);
		}
		
		mx[i] = mx[i - 1];
		mx[i] = max(mx[i], dp[i]);
	}
	
	cout << mx[n] << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--)
		solve();
	
	return 0;
}