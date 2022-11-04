#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 100005, LG = 63;
int n, dp[LG+2][MX], zero[MX], one[MX];
ll a[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	cin >> n;
	forn(i, n) cin >> a[i+1];
	sort(a+1, a+n+1);
	forn(i, n) a[i+1] = a[n] - a[i+1];

	forn(i, LG + 2) forn(j, MX) dp[i][j] = 1e9;

	dp[0][0] = 0;
	vi q(n);
	iota(all(q), 1);

	forn (j, LG) {
		forr(i, 1, n) {
			zero[i] = zero[i-1];
			one[i] = one[i-1];
			if (a[q[i-1]] & (1ll << j)) one[i]++;
			else zero[i]++;
		}

		forr(k, 0, n) {
			if (dp[j][k] == 1e9) continue;

			// Set to zero
			int x = zero[n] - zero[n - k] + one[n - k];
			int c = one[n] - one[n - k];
			dp[j+1][c] = min(dp[j+1][c], dp[j][k] + x);

			// Set to one
			x = one[n] - one[n - k] + zero[n - k];
			c = one[n] + zero[n] - zero[n - k];
			dp[j+1][c] = min(dp[j+1][c], dp[j][k] + x);
		}

		vi aux;
		for(int x : q) if (!(a[x] & (1ll << j))) aux.pb(x);
		for(int x : q) if (a[x] & (1ll << j)) aux.pb(x);
		q = aux;
	}

	cout << dp[LG][0] << endl;

	return 0;
}