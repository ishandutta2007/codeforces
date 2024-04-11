#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 503, inf = 1000000000;

int n, m, k;
vi a[MX];
int dp[MX][MX], dp2[MX][MX];
char c;

int cost (int i, int j) {
	int &res = dp2[i][j];
	if (res != -1) return res;
	res = inf;

	if (j == a[i].size()) return res = 0;

	int w = (int)a[i].size() - j - 1;
	for (int k = 0; k + w < a[i].size(); k++) 
		res = min(res, a[i][k+w] - a[i][k] + 1);
	return res;
}

int obtRes (int i, int k) {
	if (i == n) return 0;

	int &res = dp[i][k];
	if (res != -1) return res;
	res = inf;

	for (int j = 0, lim = min((int)a[i].size(), k); j <= lim; j++)
		res = min(res, obtRes(i+1, k-j) + cost(i, j));
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < MX; i++)
		for (int j = 0; j < MX; j++)
			dp[i][j] = dp2[i][j] = -1;

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> c;
			if (c == '1')
				a[i].pb(j);
		}

	cout << obtRes(0, k) << endl;

	return 0;
}