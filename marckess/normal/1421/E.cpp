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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, a[MX], vis[MX][3][3][2];
ll mem[MX][3][3][2];

ll dp (int i, int j, int k, int f) {
	if (i == n) return j == 1 && f || n == 1 ? 0 : -1e18;
	
	ll &res = mem[i][j][k][f];
	if (vis[i][j][k][f]) return res;
	vis[i][j][k][f] = 1;
	
	return res = max(
		dp(i + 1, j, 1, f || k == 1) + a[i],
		dp(i + 1, (j + 1) % 3, 0, f || k == 0) - a[i]
	);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, n) cin >> a[i];
	cout << dp(0, n % 3, 2, 0) << endl;
	
	return 0;
}