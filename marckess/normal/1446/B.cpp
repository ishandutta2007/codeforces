#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 5005;
int n, m, mem[MX][MX];
string s, t;

int dp (int i, int j) {
	if (i == n) return 0;
	if (j == m) return 0;
	
	int &res = mem[i][j];
	if (res != -1) return res;
	res = 0;
	
	if (s[i] == t[j])
		res = max(res, dp(i + 1, j + 1) + 2);
	res = max(res, dp(i + 1, j) - 1);
	res = max(res, dp(i, j + 1) - 1);
	
	return res;
}

void solve () {
	cin >> n >> m >> s >> t;
	int res = 0;
	forn (i, n) forn (j, m)
		res = max(res, dp(i, j));
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(mem, -1, sizeof(mem));
	
	int t = 1;
	// cin >> t;
	while (t--)
		solve();
		
	return 0;
}