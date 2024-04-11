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

const int MX = 1000005;
int n, m, bs[MX], to[MX], cn[MX];
ll mem[22];

ll dp (ll n) {
	if (n == 0) return 0;
	
	ll &res = mem[n];
	if (res != -1) return res;
	res = 0;
	
	forn (mk, (1 << (n - 1))) {
		ll p = 0, mn = -1, lcm = 1;
		
		mk ^= 1 << (n - 1);
		forn (i, n)
			if (mk & (1 << i)) {
				if (mn == -1)
					mn = ll(i + 1) * m;
				lcm = lcm * (i + 1) / __gcd(lcm, i + 1ll);
			}
		mk ^= 1 << (n - 1);
		
		p = mn / lcm;
		
		if (__builtin_popcount(mk) & 1) res -= p;
		else res += p;
	}
	
	return res = res + dp(n - 1);
}

void main_() {
	cin >> n >> m;
	
	for (int i = 2; i <= n; i++)
		cn[to[i]]++;
	
	ll res = 1;
	memset(mem, -1, sizeof(mem));
	
	for (int i = 2; i <= n; i++)
		res += dp(cn[i]);
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	for (ll i = 2; i < MX; i++)
		if (!bs[i]) {
			bs[i] = i;
			
			for (ll j = i * i; j < MX; j += i)
				bs[j] = i;
		}
	
	for (int i = 2; i < MX; i++) {
		vi p, ex;
		int x = i, g = 0;
		
		while (bs[x]) {
			int act = bs[x], pw = 0;
			
			while (x % act == 0) {
				x /= act;
				pw++;
			}
			
			p.pb(act);
			ex.pb(pw);
			g = __gcd(g, pw);
		}
		
		to[i] = 1;
		forn (j, p.size()) {
			ex[j] /= g;
			
			forn (kk, ex[j])
				to[i] *= p[j];
		}
	}
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}