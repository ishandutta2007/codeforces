// Powered by CP Editor (https://cpeditor.org)

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

const int MX = 300005;
int n, q, mod, c[MX], off[MX], f[MX], cn;

void update (int i, int k) {
	if (i < 2 || n < i) return;
	
	if (off[i]) cn--;
	(off[i] += k) %= mod;
	if (off[i]) cn++;
}

void main_() {
	cin >> n >> q >> mod;
	forr (i, 1, n) cin >> c[i];
	forr (i, 1, n) {
		int a;
		cin >> a;
		c[i] = (c[i] - a + mod) % mod;
	}
	
	f[1] = 1;
	f[2] = 1;
	forr (i, 3, n)
		f[i] = (f[i - 1] + f[i - 2]) % mod;
	
	forr (i, 2, n)
		update(i, (c[i] - c[i - 1] - c[i - 2]) % mod);
	
	while (q--) {
		char op;
		int l, r;
		cin >> op >> l >> r;
		
		int g = op == 'A' ? 1 : -1;
		
		(c[l] += g) %= mod;
		update(l, g);
		update(r + 1, -g * (f[r - l + 1] + f[r - l]) % mod);
		update(r + 2, -g * (f[r - l + 1]) % mod);
		
		if (!c[1] && !cn) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}