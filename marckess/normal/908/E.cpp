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

const int MX = 1005, mod = 1000000007;
int n, m;
bitset<MX> bs, s[MX];
ll res = 1, comb[MX][MX], dp[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	for (int i = 0; i < MX; i++) {
		comb[i][0] = 1;
		for (int j = 1; j <= i; j++)
			comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
	}

	dp[0] = dp[1] = 1;
	for (int i = 2; i < MX; i++)
		for (int j = 0; j < i; j++)
			(dp[i] += dp[i - j - 1] * comb[i - 1][j]) %= mod;

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			s[i][j] = c == '1';
		}
	}

	for (int i = 0; i < m; i++)
		if (!bs[i]) {
			bitset<MX> x;
			for (int j = 0; j < m; j++)
				x[j] = 1;

			for (int j = 0; j < n; j++) {
				if (s[j][i]) x &= s[j];
				else x &= ~s[j];
			}

			(res *= dp[x.count()]) %= mod;
			bs |= x;
		}

	cout << res << endl;

	return 0;
}