#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 405, mod = 998244353;
int n, c[26];
ll dp[2][MX][MX][2][2][2][2], res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, 26)
		cin >> c[i];
	
	int x = 0, y = 1 - x;
	
	forn (a, 2) forn (b, 2) forn (c, 2) forn (d, 2)
		dp[x][n + 1][n + 1][a][b][c][d] = 1; 
		
	for (int t = n - 1; t >= 0; t--) {
		forn (i, n + 2) forn (j, n + 2) forn (a, 2) forn (b, 2) forn (c, 2) forn (d, 2) {
			ll &res = dp[y][i][j][a][b][c][d];
			res = (24 - (!a && !c && t >= 2)) * dp[x][i][j][b][0][d][0];
			
			if (!a)
				res += dp[x][i == n + 1 ? i : i + 1][j][b][1][d][0];
			
			if (!c)
				res += dp[x][i][j == n + 1 ? j : j + 1][b][0][d][1];
			
			res %= mod;
		}
		
		swap(x, y);
	}
	
	res = dp[x][n + 1][n + 1][0][0][0][0];
	
	forn (i, 26)
		res -= dp[x][n - c[i]][n + 1][0][0][0][0];
	
	forn (i, 26) forn (j, i)
		res += dp[x][n - c[i]][n - c[j]][0][0][0][0];
	
	cout << MOD(res, mod) << endl;
		
	return 0;
}