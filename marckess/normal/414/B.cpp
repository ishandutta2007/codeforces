#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 2002, mod = 1000000007;
int n, k, dp[MX][MX];

int obtRes (int i, int j) {
	if (i == k)
		return 1;

	int &res = dp[i][j];
	if (res != -1) return res;
	res = 0;

	for (int k = j; k <= n; k += j) {
		res += obtRes(i+1, k);
		res %= mod;
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < MX; i++)
		for (int j = 0; j < MX; j++)
			dp[i][j] = -1;

	cin >> n >> k;
	if (k == 1) {
		cout << n << endl;
		return 0;
	}

	cout << obtRes(0, 1) << endl;

	return 0;
}