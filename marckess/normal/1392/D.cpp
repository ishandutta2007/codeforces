#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, mem[MX][2][3][2][3];
string s;

int dp (int i, int a, int b, int c, int d) {
	if (b == 3 || d == 3) return MX;
	if (i == n) {
		if (a == c && b + d >= 3) return MX;
		return 0;
	}

	int &res = mem[i][a][b][c][d];
	if (res != -1) return res;
	res = MX;

	if (!i) {
		res = min(
			dp(i + 1, 0, 1, 0, 1) + int(s[i] != 'L'),
			dp(i + 1, 1, 1, 1, 1) + int(s[i] != 'R')
		);

		return res;
	}

	if (!a) {
		if (i == b) res = min(res, dp(i + 1, 0, b + 1, c, d + 1) + int(s[i] != 'L'));
		else res = min(res, dp(i + 1, 0, b + 1, c, d) + int(s[i] != 'L'));
	} else {
		res = min(res, dp(i + 1, 0, 1, c, d) + int(s[i] != 'L'));
	}

	if (a) {
		if (i == b) res = min(res, dp(i + 1, 1, b + 1, c, d + 1) + int(s[i] != 'R'));
		else res = min(res, dp(i + 1, 1, b + 1, c, d) + int(s[i] != 'R'));
	} else {
		res = min(res, dp(i + 1, 1, 1, c, d) + int(s[i] != 'R'));
	}

	return res;
}

void solve () {
	cin >> n >> s;

	forn (i, n) memset(mem[i], -1, sizeof(mem[i]));

	cout << dp(0, 0, 0, 0, 0) << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}