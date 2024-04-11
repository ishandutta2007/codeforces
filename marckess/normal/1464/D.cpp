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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1000005, mod = 1e9 + 7;
int n, p[MX], ned[4], vis[MX];

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

vi dec () {
	vi res;
	
	for (int i = 1; i <= n; i++)
		vis[i] = 0;
	
	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			int u = i, cn = 0;
			
			do {
				vis[u] = 1;
				cn++;
				u = p[u];
			} while (u != i);
			
			res.pb(cn);
		}
	
	return res;
}

void solve () {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	
	if (n % 3 == 0) {
		ned[2] = 0;
		ned[3] = n / 3;
	} else if (n % 3 == 1) {
		ned[2] = 2;
		ned[3] = (n - 4) / 3;
	} else if (n % 3 == 2) {
		ned[2] = 1;
		ned[3] = (n - 2) / 3;
	}
	
	ll mx = pot(2, ned[2]) * pot(3, ned[3]) % mod, res = 0, cn[3] = {0};
	vi a = dec();
	
	for (int x : a) {
		res += (x - 1) / 3;
		cn[x % 3]++;
	}
	
	int d = min(cn[1], cn[2]);
	cn[1] -= d;
	cn[2] -= d;
	res += d;
	
	res += (cn[1] / 3) * 2;
	res += (cn[2] / 3) * 3;
	
	if (cn[1] % 3) {
		res++;
		
		if (cn[1] % 3 == 1) {
			int f = 1;
			
			for (int x : a)
				if (f && x >= 4 && x % 3 == 1) {
					res -= 2;
					f = 0;
				}
			
			if (f && cn[1] >= 4) {
				res--;
				f = 0;
			}
			
			if (f && d) {
				res--;
				f = 0;
			}
		}
	}
	
	cout << mx << " " << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}