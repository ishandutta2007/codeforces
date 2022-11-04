#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MX = 105;

int dp[MX][MX][2], n, p[MX];

int obtRes (int i, int j, int f) {
	if (i == n / 2)
		return 0;

	int &res = dp[i][j][f];
	if (res != -1)
		return res;
	res = 1e9;

	for (int k = j + 1; k <= n; k++)
		if (k % 2 == f)
			res = min(res, obtRes(i+1, k, f) + abs(p[i] - k));

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < MX; i++)
		for (int j = 0; j < MX; j++)
			for (int k = 0; k < 2; k++)
				dp[i][j][k] = -1;

	cin >> n;
	for (int i = 0; i < n / 2; i++)
		cin >> p[i];
	sort(p, p+n/2);

	cout << min(obtRes(0, 0, 0), obtRes(0, 0, 1)) << endl;

	return 0;
}