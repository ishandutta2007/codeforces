
// Problem : D. Top-Notch Insertions
// Contest : Codeforces - Codeforces Round #740 (Div. 1, based on VK Cup 2021 - Final (Engine))
// URL : https://codeforces.com/contest/1558/problem/D
// Memory Limit : 512 MB
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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

//RB Tree
#include <bits/extc++.h>
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;


const int MX = 400005, mod = 998244353;
int n, m, x[MX], y[MX], ex[MX];
ll fac[MX], inv[MX];
ordered_set st;

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

ll comb (int n, int k) {
	return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

void solve () {
	cin >> n >> m;
	
	vi cex, cst;
	
	forn (i, m)
		cin >> x[i] >> y[i];
		
	int a = 2 * n - 1;
	int b = n;
	
	for (int i = m - 1; i >= 0; i--) {
		auto it = st.find_by_order(y[i] - 1);
		auto jt = st.find_by_order(y[i]);
		
		if (*jt <= n && !ex[*jt]) {
			ex[*jt] = 1;
			cex.pb(*jt);
			a--;
		}
		
		cst.pb(*it);
		st.erase(it);
	}
	
	for (int i : cex) ex[i] = 0;
	for (int i : cst) st.insert(i);
	
	cout << comb(a, b) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	fac[0] = inv[0] = 1;
	for (int i = 1; i < MX; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = pot(fac[i], mod - 2);
	}
	
	for (int i = 1; i < MX / 2; i++)
		st.insert(i);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}