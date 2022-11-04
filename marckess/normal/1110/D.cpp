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

const int MX = 1000005;
int n, a[MX], m, mem[MX][4][4];

int dp (int i, int x, int y) {
	if (i > m) return 0;

	int &res = mem[i][x][y];
	if (res != -1) return res;
	res = 0;

	forn (j, 4) forn (k, x + 1) {
		if (j + k > a[i]) continue;
		int s = (a[i] - j - k) / 3;
		int r = (a[i] - j - k) % 3;

		int sx = min(x, k);
		int sy = min(y, r);

		res = max(
			res, 
			dp(i + 1, j, sx) + s + sy
		);
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	forn (i, n) {
		int in;
		cin >> in;
		a[in]++;
	}

	memset(mem, -1, sizeof(mem));
	cout << dp(1, 0, 0) << endl;

	return 0;
}