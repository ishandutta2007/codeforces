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
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 705;
int n, a[MX], g[MX][MX], mem[MX][MX][2];

int dp (int i, int j, int f) {
	if (i > j) return 1;
	int &res = mem[i][j][f];
	if (res != -1) return res;
	if (i == j) {
		if (f) return g[i][i-1] > 1;
		return g[i][i+1] > 1;
	}
	forr (k, i, j) {
		if (f && g[k][i-1] > 1)
			if (dp(i, k-1, 0) && dp(k+1, j, 1))
				return res = 1;

		if (!f && g[k][j+1] > 1)
			if (dp(i, k-1, 0) && dp(k+1, j, 1))
				return res = 1;
	}

	return res = 0;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	cin >> n;
	forn(i, n) cin >> a[i+1];
	forn(i, n+1) forn(j, n+1) g[i][j] = __gcd(a[i], a[j]);
 	
 	memset(mem, -1, sizeof(mem));
 	if (dp(1, n, 1)) cout << "YES" << endl;
 	else cout << "NO" << endl;

	return 0;
}