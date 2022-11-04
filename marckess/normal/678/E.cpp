#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int n, lim;
ld p[20][20];
vector< vector<ld> > dp;

ld obtRes (int mk, int i) {
	if (mk == lim) {
		return i == 0;
	}

	if (dp[mk][i] != -1)
		return dp[mk][i];

	ld mx = 0;
	for (int j = 0; j < n; j++) {
		if ((mk & (1 << j)) == 0) {
			mx = max (mx,
					  obtRes(mk | (1 << j), i) * p[i][j]
					  + obtRes(mk | (1 << j), j) * p[j][i]
					 );
		}
	}

	return dp[mk][i] = mx;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> p[i][j];

	if (n == 1) {
		cout << "1.000000" << endl;
		return 0;
	}

	ld res = 0;
	lim = (1 << n) - 1;
	dp = vector< vector<ld> > (lim+3, vector<ld>(n, -1));

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			int mk = (1 << i) | (1 << j);
			res = max (res, 
					   obtRes(mk, i) * p[i][j]
					   + obtRes(mk, j) * p[j][i]
					  );
		}
	}

	cout << fixed << setprecision(6) << res << endl;

	return 0;
}