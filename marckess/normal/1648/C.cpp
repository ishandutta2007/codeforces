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

const int MX = 200005, mod = 998244353;
int n, m, s[MX], t[MX];
ll ft[MX], a[MX], fac[MX];

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

void update (int i, ll k) {
	while (i < MX) {
		(ft[i] += k) %= mod;
		i += i & -i;
	}
}

ll query (int i) {
	ll s = 0;
	while (i) {
		(s += ft[i]) %= mod;
		i -= i & -i;
	}
	return s;
}

void main_() {
	cin >> n >> m;
	map<int, int> mp;
	
	forn (i, n) {
		cin >> s[i];
		mp[s[i]]++;
	}
	forn (i, m) {
		cin >> t[i];
	}
	
	ll den = 1;
	forn (i, MX)
		if (mp.count(i))
			(den *= pot(fac[mp[i]], mod - 2)) %= mod;
	
	forn (i, MX)
		if (mp.count(i)) {
			a[i] = den * mp[i] % mod;
			update(i, a[i]);
		}
	
	ll res = 0, f = 1;
	forn (i, n) {
		if (i == m)
			break;
		
		(res += fac[n - i - 1] * f % mod * query(t[i] - 1)) %= mod;
		
		if (!mp[t[i]]) break;
		
		update(t[i], -a[t[i]]);
		(f *= mp[t[i]]) %= mod;
		mp[t[i]]--;
		
		if (mp[t[i]]) {
			(a[t[i]] *= mp[t[i]]) %= mod;
			(a[t[i]] *= pot(mp[t[i]] + 1, mod - 2)) %= mod;
			update(t[i], a[t[i]]);
		}
		
		if (i + 1 == n && n < m)
			(res += 1) %= mod;
	}
	
	cout << MOD(res, mod) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	fac[0] = 1;
	for (int i = 1; i < MX; i++) {
		fac[i] = fac[i - 1] * i % mod;
	}
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}