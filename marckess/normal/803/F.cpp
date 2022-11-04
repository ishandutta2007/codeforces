#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
 
typedef long long ll;
typedef long double ld;
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MX = 100005, mod = 1e9+7;
int n, a[MX], acu[MX];
bitset<MX> bs;
vi pr;

ll pot (ll b, int p) {
	ll res = 1;

	while (p) {
		if (p & 1) res = (res * b) % mod;
		b = (b * b) % mod;
		p >>= 1;
	}

	return res;
}

void criba () {
	for (ll i = 2; i < MX; i++) {
		if (!bs[i]) {
			pr.push_back(i);
			for (ll j = i*i; j < MX; j += i)
				bs[j] = 1;
		}
	}
}

void fac (int n) {
	vi f;
	for (int i = 0; i < pr.size() && ll(pr[i]) * pr[i] <= n; i++) {
		if (n % pr[i] == 0) {
			f.push_back(pr[i]);
			while (n % pr[i] == 0)
				n /= pr[i];
		}
	}

	if (n > 1)
		f.push_back(n);

	for (int i = 1, lim = (1 << f.size()); i < lim; i++) {
		int x = 1;
		for (int j = 1, l = 0; l < f.size(); j <<= 1, l++) {
			if (i & j) {
				x *= f[l];
			}
		}
		acu[x]++;
	}
}

ll obtRes (int i, ll x, int f) {
	if (x > 100000)
		return 0;

	if (i == pr.size()) {
		if (x == 1)
			return 0;
		return (pot(2, acu[x]) - 1) * f;
	}

	if (x * pr[i] > 100000)
		return obtRes(pr.size(), x, f);

	return (obtRes(i+1, x * pr[i], -f) + obtRes(i+1, x, f)) % mod;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    criba();
	
    cin >> n;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	fac(a[i]);
    }

    cout << MOD(pot(2, n) + obtRes(0, 1, 1) - 1, mod) << endl;

    return 0;
}