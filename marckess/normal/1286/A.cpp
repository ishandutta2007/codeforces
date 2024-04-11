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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 105;
int n, a[MX], mem[MX][MX][MX][2], vis[MX], cn[2];

int dp (int i, int j, int k, int f) {
	if (j < 0 || k < 0) return 1e9;
	if (i == n) return 0;
	int &res = mem[i][j][k][f];
	if (res != -1) return res;
	if (a[i]) { 
		res = dp(i + 1, j, k, a[i] % 2) + (i && f != a[i] % 2);
	}
	else res = min(
		dp(i + 1, j - 1, k, 0) + (i && f),
		dp(i + 1, j, k - 1, 1) + (i && !f)
	);
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		vis[a[i]] = 1;
	}

	for (int i = 1; i <= n; i++)
		if (!vis[i])
			cn[i % 2]++;

	memset(mem, -1, sizeof(mem));
	cout << dp(0, cn[0], cn[1], 0) << endl;

	return 0;
}