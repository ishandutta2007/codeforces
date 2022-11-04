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

const int MX = 300005;
int n, q, a[MX], vis[MX][2];
ll mem[MX][2];

ll dp (int i, int f) {
	if (i == n) return 0;

	ll &res = mem[i][f];
	if (vis[i][f]) return res;
	vis[i][f] = 1;

	if (f)
		return res = min(dp(i + 1, 1), a[i] - dp(i + 1, 0));
	return res = max(dp(i + 1, 0), a[i] - dp(i + 1, 1));
}

void solve () {
	cin >> n >> q;
	forn (i, n) {
		cin >> a[i];
		vis[i][0] = vis[i][1] = 0;
	}
	cout << dp(0, 0) << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}