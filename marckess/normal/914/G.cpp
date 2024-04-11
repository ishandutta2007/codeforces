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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define OR 0
#define AND 1
#define XOR 2
const int MX = 1 << 17, inv2 = 5e8+4, mod = 1e9+7;

void fwt (int *a, int n, int op, int f = 0) {
	for (int len = 2; len <= n; len *= 2)
		for (int k = 0; k < n; k += len)
			for (int i = k, j = k + len / 2; j < k + len; i++, j++)
				if (f) {
					if (op == OR)
						a[j] = (a[j] - a[i] + mod) % mod;
					else if (op == AND)
						a[i] = (a[i] - a[j] + mod) % mod;
					else {
						int x = a[i], y = a[j];
						a[i] = ll(x + y) * inv2 % mod;
						a[j] = ll(x - y + mod) * inv2 % mod;
					}
				} else {
					if (op == OR)
						a[j] = (a[i] + a[j]) % mod;
					else if (op == AND)
						a[i] = (a[i] + a[j]) % mod;
					else {
						int x = a[i], y = a[j];
						a[i] = (x + y) % mod;
						a[j] = (x - y + mod) % mod;
					}
				}
}

int n, a[MX], s;
int f[MX], x[MX], y[MX], z[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	f[1] = 1;
	for (int i = 2; i < MX; i++)
		f[i] = (f[i-1] + f[i-2]) % mod;

	cin >> n;
	while (n--) {
		cin >> s;
		a[s]++;
	}

	for (int i = 0; i < MX; i++)
		y[i] = z[i] = a[i];

	for (int i = 0; i < MX; i++) {
		for (int j = i; j > 0; j = (j-1)&i)
			x[i] = (x[i] + ll(a[j]) * a[i^j]) % mod;
		x[i] = (x[i] + ll(a[0]) * a[i]) % mod;
	}

	fwt(z, MX, XOR);
	for (int i = 0; i < MX; i++)
		z[i] = ll(z[i]) * z[i] % mod;
	fwt(z, MX, XOR, 1);

	for (int i = 0; i < MX; i++) {
		x[i] = ll(x[i]) * f[i] % mod;
		y[i] = ll(y[i]) * f[i] % mod;
		z[i] = ll(z[i]) * f[i] % mod;
	}

	fwt(x, MX, AND);
	fwt(y, MX, AND);
	fwt(z, MX, AND);

	for (int i = 0; i < MX; i++)
		x[i] = ll(x[i]) * y[i] % mod * z[i] % mod;

	fwt(x, MX, AND, 1);

	ll res = 0;
	for (int i = 0; i < 17; i++)
		res = (res + x[1<<i]) % mod;
	cout << res << endl;

	return 0;
}