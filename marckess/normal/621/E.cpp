#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int mod = 1'000'000'007;
int n, b, k, x, a[10], y;

ll pot (ll b, int p, int mod) {
	ll res = 1;

	while (p) {
		if (p & 1)
			res = res * b % mod;
		b = b * b % mod;
		p /= 2;
	}

	return res;
}

vi mul (vi g, vi h, int e, int f) {
	vi res(x);
	ll off = pot(10, f, x);

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			res[(off * i + j) % x] += (ll)g[i] * h[j] % mod;
			res[(off * i + j) % x] %= mod;
		}
	}

	return res;
}

vi pot (vi b, int p) {
	vi res(x);
	res[0] = 1;
	int e = 0, f = 1;

	while (p) {
		if (p & 1) {
			res = mul(res, b, e, f);
			e += f;
		}

		b = mul(b, b, f, f);
		f *= 2;
		p /= 2;
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> b >> k >> x;
	for (int i = 0; i < n; i++) {
		cin >> y;
		a[y]++;
	}

	vi t(x);
	for (int i = 1; i < 10; i++)
		t[i%x] += a[i];

	cout << pot(t, b)[k] << endl;;

	return 0;
}