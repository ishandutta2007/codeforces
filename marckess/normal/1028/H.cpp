#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MA = 5100000, MN = 200000;

int n, a[MN], h[MA];
bitset<MA> bs;
vi pr, fac[MA];

void criba () {
	for (ll i = 2; i * i < MA; i++)
		if (!bs[i]) {
			pr.pb(i);
			for (ll j = i * i; j * j < MA; j += i)
				bs[j] = 1;
		}
}

void obtFac (int n) {
	int x = n;

	for (int i = 0; i < pr.size() && pr[i] * pr[i] <= x; i++) {
		int pw = 0;
		while (x % pr[i] == 0) {
			x /= pr[i];
			pw++;
		}
		if (pw & 1)
			fac[n].pb(pr[i]);
	}

	if (x > 1)
		fac[n].pb(x);
}

int q, l[10*MN], r[10*MN], res[10*MN], d[20], sig[MA][10];
vi pos[MN];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(d, -1, sizeof(d));
	memset(sig, -1, sizeof(sig));
	fill(res, res+10*MN, 20);
	criba();

	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (fac[a[i]].empty())
			obtFac(a[i]);
	}

	for (int i = 0; i < q; i++) {
		cin >> l[i] >> r[i];
		l[i]--, r[i]--;
		pos[r[i]].pb(i);
	}

	for (int i = 0; i < n; i++) {
		vi &v = fac[a[i]];
		for (int j = 0; j < (1 << v.size()); j++) {
			int x = 1, cn = v.size();
			for (int k = 0; k < v.size(); k++)
				if (j & (1 << k)) {
					x *= v[k];
					cn--;
				}

			for (int j = 0; j < 8; j++)
				d[j+cn] = max(d[j+cn], sig[x][j]);
			sig[x][cn] = i;
		}

		for (int j : pos[i])
			for (int k = 0; k < 15; k++)
				if (d[k] >= l[j]) {
					res[j] = k;
					break;
				}
	}

	for (int i = 0; i < q; i++)
		cout << res[i] << endl;


	return 0;
}