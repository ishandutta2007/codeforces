#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 2005;
int n, k, x[MX][MX];
char a[MX][MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];

	for (int i = 1; i <= n; i++) {
		int mx = 0, mn = 0;
		for (int j = 1; j <= n; j++)
			if (a[i][j] == 'B') {
				if (!mn) mn = j;
				mx = j;
			}
		if (!mx) x[1][1]++;
		else if (mx - mn + 1 <= k) {
			int tx = i + k - 1;
			int ty = mn + k - 1;
			x[i][mx]++;
			if (tx < n) x[tx+1][mx]--;
			if (ty < n) x[i][ty+1]--;
			if (tx < n && ty < n) x[tx+1][ty+1]++;
		}
	}

	for (int j = 1; j <= n; j++) {
		int mx = 0, mn = 0;
		for (int i = 1; i <= n; i++)
			if (a[i][j] == 'B') {
				if (!mn) mn = i;
				mx = i;
			}
		if (!mx) x[1][1]++;
		else if (mx - mn + 1 <= k) {
			int tx = mn + k - 1;
			int ty = j + k - 1;
			x[mx][j]++;
			if (tx < n) x[tx+1][j]--;
			if (ty < n) x[mx][ty+1]--;
			if (tx < n && ty < n) x[tx+1][ty+1]++;
		}
	}

	int res = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			x[i][j] += x[i][j-1] + x[i-1][j] - x[i-1][j-1];
			res = max(res, x[i][j]);
		}
	cout << res << endl;
 
	return 0;
}