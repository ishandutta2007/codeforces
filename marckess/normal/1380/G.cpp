#include <bits/stdc++.h>

#define endl '\n'
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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int mod = 998244353, MX = 600005;
int n;
ll c[MX], acu[MX];

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	forn (i, n)
		cin >> c[i];
	sort(c, c + n, greater<ll>());

	forn (i, n) {
		acu[i] = c[i];
		if (i) (acu[i] += acu[i - 1]) %= mod;
	}

	for (int i = n; i <= 2 * n; i++)
		acu[i] = acu[i - 1];

	for (int i = 1; i <= n; i++) {
		ll s = 0;

		for (ll j = i, k = 1; j < n; j += i, k++)
			(s += k * (acu[j + i - 1] - acu[j - 1])) %= mod;
	
		cout << MOD(s * pot(n, mod - 2), mod) << " ";
	}
	cout << endl;

	return 0;
}