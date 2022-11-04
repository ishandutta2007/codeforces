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

const int MX = 100005;
const ll inf = 1e18;
int n, a[MX][3], vis[MX][3];
ll s[MX], mem[MX][3];

ll dp (int i, int j) {
	if (i == n) {
		if (j == 2) return 0;
		return -inf;
	}
	if (i > n) return -inf;

	ll &res = mem[i][j];
	if (vis[i][j]) return res;
	vis[i][j] = 1;
	res = -inf;

	if (j == 0) {
		res = max({
			a[i][0] + dp(i + 1, 0),
			a[i][0] + a[i][1] + dp(i + 1, 1),
			s[i] + dp(i + 1, 2),
			s[i] + s[i + 1] + dp(i + 2, 2)
		});
	}

	if (j == 1) {
		res = max({
			a[i][1] + dp(i + 1, 1),
			a[i][1] + a[i][0] + dp(i + 1, 0),
			a[i][1] + a[i][2] + dp(i + 1, 2),
		});
	}

	if (j == 2) {
		res = max({
			a[i][2] + dp(i + 1, 2),
			a[i][2] + a[i][1] + dp(i + 1, 1),
			s[i] + dp(i + 1, 0),
			s[i] + s[i + 1] + dp(i + 2, 0)
		});
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	forn (j, 3) forn (i, n) {
		cin >> a[i][j];
		s[i] += a[i][j];
	}
	cout << dp(0, 0) << endl;

	return 0;
}