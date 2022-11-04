#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int mod = 1e9 + 7;
int k;
ll n, res = 1, d[100], inv[100], mem[55][10005];

ll pot (ll b, int p) {
	ll res = 1;
	
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p  /= 2;
	}
	
	return res;
}

ll dp (int p, int k) {
	if (k == 0) return d[p];
	
	ll &res = mem[p][k];
	if (res != -1) return res;
	res = 0;
	
	for (int i = 0; i <= p; i++)
		res += dp(i, k - 1);
	res %= mod;
	
	(res *= inv[p]) %= mod;
	
	return res;
}

ll f (ll x, int p) {
	d[0] = 1;
	d[1] = x % mod;
	
	inv[0] = 1;
	inv[1] = pot(2, mod - 2);
	
	for (int i = 2; i <= p; i++) {
		d[i] = d[i - 1] * d[1] % mod;
		inv[i] = pot(i + 1, mod - 2);
	}
	
	memset(mem, -1, sizeof(mem));
	return dp(p, k);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	
	for (ll i = 2; i * i <= n; i++)
		if (n % i == 0) {
			int pw = 0;
			while (n % i == 0) {
				n /= i;
				pw++;
			}
			(res *= f(i, pw)) %= mod;
		}
	
	if (n > 1)
		(res *= f(n, 1)) %= mod;
	
	cout << res << endl;
	
	return 0;
}