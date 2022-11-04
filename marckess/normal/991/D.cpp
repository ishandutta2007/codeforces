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

int n, dp[105][2][2];
string s[2];

int obtRes (int i, int a, int b) {
	if (i == n)
		return 0;

	int &_ = dp[i][a][b];
	if (_ != -1)
		return _;
	_ = obtRes(i+1, s[0][i], s[1][i]);

	if (s[0][i] && a && b)
		_ = max(_, obtRes(i+1, 0, s[1][i]) + 1);

	if (s[0][i] && s[1][i] && a)
		_ = max(_, obtRes(i+1, 0, 0) + 1);

	if (s[0][i] && s[1][i] && b)
		_ = max(_, obtRes(i+1, 0, 0) + 1);

	if (s[1][i] && a && b)
		_ = max(_, obtRes(i+1, s[0][i], 0) + 1);

	return _;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 105; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				dp[i][j][k] = -1;

	cin >> s[0] >> s[1];
	n = s[0].size();
	
	for (int i = 0; i < 2; i++)
		for (char &c : s[i])
			if (c == '0')
				c = 1;
			else
				c = 0;

	cout << obtRes(0, 0, 0) << endl;

	return 0;
}