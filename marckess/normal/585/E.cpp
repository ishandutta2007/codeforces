#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 5e5+5, MA = 1e7+5, mod = 1e9+7;
int n, a[MX], bs[MA];
ll res = 0, acu = 0;
int mob[MA], cn[MA], pw[MA];
vi f[MX];

void precal () {
	mob[1] = bs[1] = 1;

	for (ll i = 2; i < MA; i++) {
		if (!bs[i]) {
			bs[i] = i;
			for (ll j = i * i; j < MA; j += i)
				bs[j] = i;
		}

		int x = i / bs[i];
		if (x % bs[i])
			mob[i] = -mob[x];
	}
}

ll pot (ll b, int p) {
	ll res = 1;

	while (p) {
		if (p & 1) res = res * b % mod;
		b = b * b % mod;
		p /= 2;
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	precal();

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];

		int x = a[i];
		while (x > 1) {
			int p = bs[x];
			f[i].pb(p);

			while (x % p == 0)
				x /= p;
		}

		for (int k = 0; k < (1 << f[i].size()); k++) {
			int x = 1;

			for (int j = 0; j < f[i].size(); j++)
				if (k & (1 << j))
					x *= f[i][j];

			cn[x]++;
		}
	}

	for (int i = 1; i < MA; i++)
		if (mob[i]) {
			pw[i] = pot(2, cn[i]);
			acu += mob[i] * (pw[i] - 1);
			
			if (acu >= mod) acu -= mod;
			if (acu < 0) acu += mod;
		}

	res = MOD(-n * acu, mod);

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < (1 << f[i].size()); k++) {
			int x = 1;

			for (int j = 0; j < f[i].size(); j++)
				if (k & (1 << j))
					x *= f[i][j];

			res += mob[x] * (pw[x] - 1);
			if (acu >= mod) acu -= mod;
			if (acu < 0) acu += mod;
		}
	}

	cout << MOD(res, mod) << endl;

	return 0;
}