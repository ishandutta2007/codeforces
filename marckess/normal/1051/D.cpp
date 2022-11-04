#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 1005, mod = 998244353;
int n, k, dp[MX][2*MX][2][2];

int obtRes (int i, int j, int f, int g) {
	if (j > k) return 0;

	if (i == n) {
		j++;
		if (f != g) j++;
		return j == k;
	}

	int &res = dp[i][j][f][g];
	if (res != -1) return res;

	res = 0;
	for (int k = 0; k < 2; k++)
		for (int l = 0; l < 2; l++) {
			if (k == l)
				res = (res + obtRes(i+1, j + (k != f || l != g), k, l)) % mod;
			else if (k != f && l != g)
				res = (res + obtRes(i+1, j+2, k, l)) % mod;
			else
				res = (res + obtRes(i+1, j, k, l)) % mod;
		}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(dp, -1, sizeof(dp));

	cin >> n >> k;

	int res = 0;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			res = (res + obtRes(1, 0, i, j)) % mod;

	cout << res << endl;

	return 0;
}