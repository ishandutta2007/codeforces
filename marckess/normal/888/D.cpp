#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 1005;
ll dp[MX][MX];
int n, k;
ll res = 1;

ll c (int n, int k) {
	if (n < 0 || k < 0 || k > n)
		return 0;

	if (k == 0 || n == k)
		return 1;

	if (dp[n][k] != -1)
		return dp[n][k];

	return dp[n][k] = c(n-1, k) + c(n-1, k-1);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < MX; i++)
		for (int j = 0; j < MX; j++)
			dp[i][j] = -1;

	cin >> n >> k;

	if (k >= 2)
		res += c(n, 2);

	if (k >= 3)
		res += 2 * c(n, 3);

	if (k >= 4)
		res += 9 * c(n, 4);

	cout << res << endl;

	return 0;
}