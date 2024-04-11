#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 505, mod = 998244353;
int n, dp[MX][MX], a[MX];
char op[MX];

void sum (int &a, int b) {
	a += b;
	if (a >= mod)
		a -= mod;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n;
	forn (i, n) {
		cin >> op[i];
		if (op[i] == '+')
			cin >> a[i];
	}
	
	ll res = 0;
	forn (i, n)
		if (op[i] == '+') {
			memset(dp, 0, sizeof(dp));
			
			dp[0][0] = 1;
			forn (j, i)
				forn (k, n) {
					sum(dp[j + 1][k], dp[j][k]);
					
					if (op[j] == '+')
						sum(dp[j + 1][k + (a[j] <= a[i])], dp[j][k]);
					else
						sum(dp[j + 1][max(0, k - 1)], dp[j][k]);
				}
			
			forn (k, n)
				dp[i + 1][k + 1] = dp[i][k];
			
			for (int j = i + 1; j < n; j++)
				for (int k = 1; k < n; k++) {
					sum(dp[j + 1][k], dp[j][k]);
					
					if (op[j] == '+')
						sum(dp[j + 1][k + (a[j] < a[i])], dp[j][k]);
					else if (k > 1)
						sum(dp[j + 1][k - 1], dp[j][k]);
				}
			
			int p = 0;
			for (int k = 1; k <= n; k++)
				sum(p, dp[n][k]);
			
			(res += 1ll * a[i] * p) %= mod;
		}
	
	cout << res << endl;
	
	return 0;
}