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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, a[MX], bs[MX];
ll res = 1;
vi pos[MX];

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) res *= b;
		b *= b;
		p /= 2;
	}
	return res;
}

void fac (int n) {
	while (n > 1) {
		int p = bs[n];
		int pw = 0;

		while (n % p == 0) {
			n /= p;
			pw++;
		}

		pos[p].pb(pw);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	for (ll i = 2; i < MX; i++)
		if (!bs[i]) {
			bs[i] = i;
			for (ll j = i * i; j < MX; j += i)
				bs[j] = i;
		}

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		fac(a[i]);
	}

	forn (i, MX) {
		sort(all(pos[i]));
		if (pos[i].size() == n - 1) res *= pot(i, pos[i][0]);
		if (pos[i].size() == n) res *= pot(i, pos[i][1]);
	}

	cout << res << endl;

	return 0;
}