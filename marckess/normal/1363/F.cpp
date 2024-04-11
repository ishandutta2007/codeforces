#include <bits/stdc++.h>
 
//#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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

const int MX = 2005;
int n, mem[MX][MX], as[MX][256], at[MX][256];
string s, t, _s, _t;

int dp (int i, int j) {
	if (i > j) return 0;
	if (i == n || j == n) return 0;

	int &res = mem[i][j];
	if (res != -1) return res;
	res = 0;

	if (s[i] == t[j]) res = max(res, dp(i + 1, j + 1) + 1);
	
	if (as[i + 1][s[i]] >= at[j][s[i]])
		res = max(res, dp(i + 1, j));

	if (as[i + 1][t[j]] >= at[j][t[j]])
		res = max(res, dp(i, j + 1));

	return res;
}

void solve () {
	cin >> n >> s >> t;

	_s = s;
	_t = t;

	sort(all(_s));
	sort(all(_t));

	if (_s != _t) {
		cout << -1 << endl;
		return;
	}

	memset(as[n], 0, sizeof(as[n]));
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 'a'; j <= 'z'; j++)
			as[i][j] = as[i + 1][j];
		as[i][s[i]]++;
	}

	memset(at[n], 0, sizeof(at[n]));
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 'a'; j <= 'z'; j++)
			at[i][j] = at[i + 1][j];
		at[i][t[i]]++;
	}

	forn (i, n + 1) forn (j, n + 1) mem[i][j] = -1; 

	cout << n - dp(0, 0) << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}