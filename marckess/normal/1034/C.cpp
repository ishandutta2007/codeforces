#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1e6+5, mod = 1e9+7;
int n, p;
ll a[MX], s[MX], cn[MX], dp[MX];
vi adj[MX];

void dfs (int u) {
	s[u] = a[u];
	for (int v : adj[u]) {
		dfs(v);
		s[u] += s[v];
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 2; i <= n; i++) {
		cin >> p;
		adj[p].pb(i);
	}

	dfs(1);

	for (int i = n; i > 0; i--)
		if (s[1] / __gcd(s[1], s[i]) <= n)
			cn[s[1] / __gcd(s[1], s[i])]++;

	for (int i = n; i > 0; i--)
		for (int j = 2 * i; j <= n; j += i)
			cn[j] += cn[i];

	for (int i = n; i > 0; i--)
		if (cn[i] == i) {
			dp[i] = 1;
			for (int j = 2 * i; j <= n; j += i) {
				dp[i] += dp[j];
				if (dp[i] >= mod)
					dp[i] -= mod;
			}
		}

	cout << dp[1] << endl;

	return 0;
}