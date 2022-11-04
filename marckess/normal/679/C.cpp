#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 510;
int n, k;
char mp[MX][MX];
int a[MX][MX], sz[MX*MX], acu[MX*MX], pre[MX][MX], cn = 0;
int mv[] = {1, 0, -1, 0, 0, 1, 0, -1};
bitset<MX> bs[MX];
int res = 0, par = 0;

void dfs (int i, int j, int cn) {
	a[i][j] = cn;
	sz[cn]++;
	bs[i][j] = 1;

	for (int l = 0; l < 4; l++) {
		int x = i + mv[l*2];
		int y = j + mv[l*2+1];

		if (bs[x][y] || mp[x][y] != '.')
			continue;
		dfs(x, y, cn);
	}
}

void sum (int i, int k) {
	if (acu[i] == 1 && k == -1)
		par -= sz[i];
	if (acu[i] == 0 && k == 1)
		par += sz[i];
	acu[i] += k;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> mp[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (!bs[i][j] && mp[i][j] == '.')
				dfs(i, j, ++cn);

	n += 2;
	k += 2;

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (mp[i][j] == 'X') pre[i][j] = 1;
			pre[i][j] += pre[i-1][j];
			pre[i][j] += pre[i][j-1];
			pre[i][j] -= pre[i-1][j-1];
		}
	}

	for (int i = 0; i + k <= n; i++) {
		for (int l = 0; l <= cn; l++)
			acu[l] = 0;
		par = 0;

		for (int j = 0; j < n; j++) {
			for (int l = 1; l + 1 < k; l++)
				sum(a[i+l][j], 1);
			
			if (j - k >= 0) {
				for (int l = 1; l + 1 < k; l++)
					sum(a[i+l][j-k], -1);
				sum(a[i][j-k+1], -1);
				sum(a[i+k-1][j-k+1], -1);
			}

			if (i + k - 2 >= 0 && j - k + 1 >= 0 && j - 1 >= 0) {
				res = max(
						res,
						par + pre[i+k-2][j-1] - pre[i+k-2][j-k+1] - pre[i][j-1] + pre[i][j-k+1] 
					);
			}

			sum(a[i][j], 1);
			sum(a[i+k-1][j], 1);
		}
	}

	cout << res << endl;

	return 0;
}