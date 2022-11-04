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

const int MX = 100005, mod = 1e9+7;
int n, a[MX], dp[10*MX];
vi d[10*MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 1; i < 10*MX; i++) {
		for (int j = i; j < 10*MX; j += i)
			d[j].pb(i);
		reverse(all(d[i]));
	}

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	dp[0] = 1;
	for (int i = 0; i < n; i++)
		for (int k : d[a[i]]) {
			dp[k] += dp[k-1];
			if (dp[k] >= mod) dp[k] -= mod;
		}

	ll res = 0;
	for (int i = 1; i < 10*MX; i++) res += dp[i];
	cout << res % mod << endl;

	return 0;
}