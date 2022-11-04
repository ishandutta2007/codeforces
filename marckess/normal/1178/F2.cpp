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
 
const int MX = 505, mod = 998244353;
int n, m;
vi c, pos[MX];
ll mem[2*MX][2*MX];
 
bool isValid (int a, int b) {
	if (a != pos[c[a]][0] && a != pos[c[a]].back()) return 0;
	if (b != pos[c[b]][0] && b != pos[c[b]].back()) return 0;
	for (int i = 1; i <= n; i++)
		if ((a <= pos[i][0] && pos[i][0] <= b) != (a <= pos[i].back() && pos[i].back() <= b)) return 0;
	return 1;
}

ll dp (int a, int b) {
	if (a > b) return 1;
	
	ll &res = mem[a][b];
	if (res != -1) return res;
	if (!isValid(a, b)) return res = 0;
 
	int mn = c[a];
	for (int i = a; i <= b; i++)
		mn = min(mn, c[i]);
 	
 	int ind = pos[mn][0];
	ll x = dp(a, ind - 1);
	for (int i = a; i < ind; i++)
		x += dp(a, i) * dp(i + 1, ind - 1) % mod;
	x %= mod;
 	
 	ind = pos[mn].back();
	ll y = dp(ind + 1, b);
	for (int i = ind + 1; i <= b; i++)
		y += dp(ind + 1, i) * dp(i + 1, b) % mod;
	y %= mod;

 	res = 1;
 	for (int i = 0; i + 1 < pos[mn].size(); i++)
 		(res *= dp(pos[mn][i] + 1, pos[mn][i + 1] - 1)) %= mod;

 	(res *= x) %= mod;
 	(res *= y) %= mod;
	return res;
}
 
int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	cin >> n >> m;
	c.resize(m);
	forn(i, m) cin >> c[i];
	c.erase(unique(all(c)), c.end());

	if (c.size() > 2 * n) {
		cout << 0 << endl;
		return 0;
	}

	m = c.size();
	for (int i = 0; i < m; i++)
		pos[c[i]].pb(i);

	memset(mem, -1, sizeof(mem));
	cout << dp(0, m - 1) << endl;
 
	return 0;
}