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

const int MX = 100005;
int n;
ld x[MX], y[MX], ax, ay, bx, by, tx, ty;
ld dp[MX][2][2];

ld obtRes (int i, int j, int k) {
	if (i == n) {
		if (j || k)
			return 0;
		else
			return 1e32;
	}

	ld &_ = dp[i][j][k];
	if (_ != -1)
		return _;

	_ = obtRes(i+1, j, k) + 2 * hypot(x[i] - tx, y[i] - ty);

	if (!j)
		_ = min(_, obtRes(i+1, 1, k) + hypot(x[i] - ax, y[i] - ay) + hypot(x[i] - tx, y[i] - ty));

	if (!k)
		_ = min(_, obtRes(i+1, j, 1) + hypot(x[i] - bx, y[i] - by) + hypot(x[i] - tx, y[i] - ty));

	return _;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < MX; i++)
	for (int j = 0; j < 2; j++)
	for (int k = 0; k < 2; k++)
		dp[i][j][k] = -1;

	cin >> ax >> ay >> bx >> by >> tx >> ty >> n;
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];

	cout << fixed << setprecision(10) << obtRes(0, 0, 0) << endl;

	return 0;
}