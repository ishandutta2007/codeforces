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

const int MX = 200005;
int n, a, b;
string s;
ll mem[MX][2];

ll dp (int i, int j) {
	if (i == n) return j ? 1e18 : 0;
	ll &res = mem[i][j];
	if (res != -1) return res;
	res = 1e18;
	if (s[i] == '1' && !j) return res;
	res = a + (1 + j) * b + dp(i+1, j);
	if (s[i] == '0') res = min(res, dp(i+1, 1 - j) + 2 * a + (2 - j) * b);
	return res;
}

void solve () {
	cin >> n >> a >> b >> s;
	memset(mem, -1, sizeof(mem));
	cout << dp(0, 0) + b << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}