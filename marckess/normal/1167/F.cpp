#include <bits/stdc++.h>

//#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 500005, mod = 1000000007;
int n, a[MX], q[MX];
ll res = 0;

struct FT {
	ll ft[MX];
	FT () { memset(ft, 0, sizeof(ft)); }
	void update (int i, int k) {
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
	ll query (int a, int b) {
		return (query(b) - query(a-1) + mod) % mod;
	}
}izq, der;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	iota(q, q+n, 1);
	sort(q, q+n, [&] (int i, int j) {
		return a[i] < a[j];
	});

	for (int i = 0; i < n; i++) {
		int u = q[i];
		izq.update(u, u);
		
		ll acu = u * der.query(u, n) % mod;
		(acu += izq.query(1, u) * (n - u + 1)) %= mod;
		(res += a[u] * acu) %= mod;

		der.update(u, n - u + 1);
	}

	cout << MOD(res, mod) << endl;

	return 0;
}