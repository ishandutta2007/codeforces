#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 200005, mod = 998244353;
int n, q;
ll p[MX], u, pi = 1, acu[MX], sum[MX], tri[MX], res;
set<int> st;

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

ll f (int i, int j) {
	ll p = (tri[j] - tri[i - 1]) % mod;
	(p -= (i - 1) * (sum[j] - sum[i - 1])) %= mod;
	(p *= pot(acu[i - 1], mod - 2)) %= mod;
	(p += (j - i + 1) * acu[j] % mod * pot(acu[i - 1], mod - 2)) %= mod;

	ll q = (sum[j] - sum[i - 1]) % mod;
	(q *= pot(acu[i - 1], mod - 2)) %= mod;
	q = 1 - q;

	return p * pot(q, mod - 2) % mod;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	acu[0] = 1;

	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];

		(p[i] *= pot(100, mod - 2)) %= mod;
		(pi *= p[i]) %= mod;
		acu[i] = p[i] * acu[i - 1] % mod;
		sum[i] = (sum[i - 1] + acu[i - 1] * (1 - p[i])) % mod;
		tri[i] = (tri[i - 1] + i * acu[i - 1] % mod * (1 - p[i]) % mod);
	}

	st.insert(0);
	st.insert(1);
	st.insert(n + 1);

	res = MOD(f(1, n), mod);

	while (q--) {
		cin >> u;
	
		if (st.count(u)) {
			auto it = st.find(u);

			it++;
			int sig = *it;

			it--; it--;
			int ant = *it;

			res -= f(ant, u - 1);
			res -= f(u, sig - 1);
			res += f(ant, sig - 1);

			st.erase(u);
		} else {
			auto it = st.upper_bound(u);

			int sig = *it;

			it--;
			int ant = *it;

			res -= f(ant, sig - 1);
			res += f(ant, u - 1);
			res += f(u, sig - 1);

			st.insert(u);
		}

		res = MOD(res, mod);
		cout << res << endl;
	}

	return 0;
}