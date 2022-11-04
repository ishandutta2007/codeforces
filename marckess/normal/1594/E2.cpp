
// Problem : E2. Rubik's Cube Coloring (hard version)
// Contest : Codeforces - Codeforces Round #747 (Div. 2)
// URL : https://codeforces.com/contest/1594/problem/E2
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int mod = 1000000007;

ll pot (ll b, ll p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

int k, m;
vii a;
map<ll, ll> mp, mem[7];

ll dp (ll i, ll f, int lvl) {
	if (!lvl) return 1;
	
	if (mem[f].count(i))
		return mem[f][i];
	
	ll &res = mem[f][i];
	res = 0;
	
	if (!mp.count(i))
		return res = (i == 1 ? 6 : 4) * pot(4, (1ll << lvl) - 2) % mod;
	
	forn (c, 6) {
		if (c / 2 == f / 2) continue;
		if (mp[i] != -1 && mp[i] != c) continue;
		
		(res += dp(2 * i, c, lvl - 1) * dp(2 * i + 1, c, lvl - 1)) %= mod;
	}

	return res;
}

void main_() {
	cin >> k >> m;
	
	while (m--) {
		ll v, y;
		string x;
		
		cin >> v >> x;
		
		if (x == "white") y = 0;
		if (x == "yellow") y = 1;
		if (x == "green") y = 2;
		if (x == "blue") y = 3;
		if (x == "red") y = 4;
		if (x == "orange") y = 5;
		
		a.pb({v, y});
		
		while (v) {
			mp[v] = -1;
			v /= 2;
		}
	}
	
	for (ii p : a)
		mp[p.fi] = p.se;
	
	cout << dp(1, 6, k) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}