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

const int MX = 505;
int n, a[MX];
int mem[MX][MX];

int dp (int i, int j) {
	if (i >= j)
		return 0;

	int &res = mem[i][j];
	if (res != -1)
		return res;

	res = min(dp(i, j-1), dp(i+1, j)) + 1;
	for (int k = i; k <= j; k++) {
		if (i != k && a[i] == a[k]) {
			int d = 0;
			if (k + 1 <= j)
				d = dp(k+1, j) + 1;
			res = min(res, dp(i+1, k-1) + d);
		}

		if (k != j && a[k] == a[j]) {
			int d = 0;
			if (i <= k - 1)
				d = dp(i, k - 1) + 1;
			res = min(res, dp(k+1, j-1) + d);
		}
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < MX; i++)
		for (int j = 0; j < MX; j++)
			mem[i][j] = -1;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << dp(0, n-1) + 1 << endl;

	return 0;
}