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

const int MX = 200005;
int n, c, a[MX], b[MX], dp[MX][2];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> c;
	forn(i, n-1) cin >> a[i+1];
	forn(i, n-1) cin >> b[i+1];

	for (int i = 1; i <= n; i++) {
		dp[i][1] = min(dp[i-1][0] + a[i-1], dp[i-1][1] + b[i-1]);
		dp[i][0] = min(dp[i-1][0] + a[i-1], dp[i][1] + c);
		cout << dp[i][0] << " ";
	}
	cout << endl;

	return 0;
}