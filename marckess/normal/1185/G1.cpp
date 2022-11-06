#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int mod = 1000000007;
int n, m, t[15], g[15], mem[1<<15][230][4];

int dp (int i, int j, int k) {
	if (j > m) return 0;
	if (j == m) return 1;
	int &res = mem[i][j][k];
	if (res != -1) return res;
	res = 0;
	for (int l = 0; l < n; l++)
		if (!(i & (1 << l)) && g[l] != k) {
			res += dp(i | (1 << l), j + t[l], g[l]);
			if (res >= mod) res -= mod;
		}
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	forn(i, n) { cin >> t[i] >> g[i]; g[i]--; }
	memset(mem, -1, sizeof(mem));
	cout << dp(0, 0, 3) << endl;

	return 0;
}