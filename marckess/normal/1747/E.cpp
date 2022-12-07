#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
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

const int MX = 5000005, mod = 1000000007;
int n, m;
ll fac[MX], inv[MX], pot2[2 * MX];

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
	if (n < 0 || k < 0 || n < k) return 0;
	return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

ll f (ll n) {
	if (n < 2) return n + 1;
	return pot2[n - 2] * (n + 3) % mod;
}

void main_() {
	cin >> n >> m;
	
	ll res = 0;
	forr (i, 0, n) {
		ll p = comb(n, i) * comb(m, i) % mod;
		(p *= f(n + m - i) + pot2[n + m - i - 1] * i % mod) %= mod;
		(res += p) %= mod;
	}
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	fac[0] = 1;
	forr (i, 1, MX - 1)
		fac[i] = fac[i - 1] * i % mod;
	
	inv[0] = inv[1] =1;
	forr (i, 2, MX - 1)
		inv[i] = inv[mod % i] * (mod - mod / i) % mod;
	
	forr (i, 2, MX - 1)
		(inv[i] *= inv[i - 1]) %= mod;
	
	pot2[0] = 1;
	forr (i, 1, 2 * MX - 1)
		pot2[i] = 2 * pot2[i - 1] % mod;
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}