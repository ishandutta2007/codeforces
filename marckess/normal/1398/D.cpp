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

const int MX = 205;
int a, b, c, x[MX], y[MX], z[MX], mem[MX][MX][MX];

int dp (int i, int j, int k) {
	int &res = mem[i][j][k];
	if (res != -1) return res;
	res = 0;

	if (i < a && j < b) res = max(res, dp(i + 1, j + 1, k) + x[i] * y[j]);
	if (j < b && k < c) res = max(res, dp(i, j + 1, k + 1) + y[j] * z[k]);
	if (k < c && i < a) res = max(res, dp(i + 1, j, k + 1) + z[k] * x[i]);

	return res;
}
 
int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(mem, -1, sizeof(mem));
	
	cin >> a >> b >> c;

	forn (i, a) cin >> x[i];
	forn (i, b) cin >> y[i];
	forn (i, c) cin >> z[i];

	sort(x, x + a, greater<int>());
	sort(y, y + b, greater<int>());
	sort(z, z + c, greater<int>());

	cout << dp(0, 0, 0) << endl;

	return 0;
}