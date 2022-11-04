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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 200005;
int H, n, h[MX], mem[MX];

int dp (int i) {
	int &res = mem[i];
	if (res != -1) return res;

	if (i == n) return res = 0;
	if (i + 1 == n) return res = 0;

	if (i + 2 == n) {
		if (h[i+1] == 1)
			return res = 0;
		return res = dp(i + 1) + 1;
	}

	return res = min(
		dp(i + 1) + 1,
		dp(i + 2) + 2 * (h[i+1] != h[i+2] + 1)
	);
}

void solve () {
	cin >> H >> n;
	forn (i, n) cin >> h[i];
	h[n] = 0;
	forr (i, 0, n) mem[i] = -1;
	cout << dp(0) << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}