#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005, LMX = 17, mod = 1e9+7;

struct FT {
	ll ft[MX];

	FT () { memset(ft, 0, sizeof(MX)); }

	void update (int i, ll k, bool f = true) {
		while (i < MX) {
			ft[i] += k;
			if (f) ft[i] %= mod;
			i += i & -i;
		}
	}

	ll query (int i, bool f = true) {
		ll sum = 0;
		while (i) {
			sum += ft[i];
			if (f) sum %= mod;
			i -= i & -i;
		}
		return sum;
	}

	ll query (int a, int b, bool f = true) {
		ll res = query(b, f) - query(a-1, f);
		if (f) res = MOD(res, mod);
		return res;
	}

	int find (ll k) {
		int pos = 0;

		for (int i = LMX; i >= 0; i--)
			if (pos + (1 << i) < MX && ft[pos + (1 << i)] < k) {
				pos += 1 << i;
				k -= ft[pos];
			}

		return pos+1;
	}
}sum, acu;

int n, q, x, y;
ll a[MX], w[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> w[i];

	for (int i = 1; i <= n; i++) {
		a[i] -= i;
		sum.update(i, w[i], false);
		acu.update(i, a[i] * w[i] % mod);
	}

	while (q--) {
		cin >> x >> y;

		if (x < 0) {
			x = -x;
			sum.update(x, y - w[x], false);
			acu.update(x, a[x] * (y - w[x]) % mod);
			w[x] = y;
		} else {
			ll res = 0;
			int k = sum.find(sum.query(x-1, false) + sum.query(x, y, false) / 2 + 1);
			
			if (x < k) res += sum.query(x, k-1) * a[k] - acu.query(x, k-1);
			if (k < y) res += acu.query(k+1, y) - sum.query(k+1, y) * a[k];

			cout << MOD(res, mod) << endl;
		}
	}

	return 0;
}