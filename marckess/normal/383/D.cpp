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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 10005, mod = 1000000007;
int n, a[MX];
ll mp[2 * MX + 5], cn[2][2 * MX + 5], res;

void sum (ll &a, ll b) {
	a += b;
	if (a >= mod) a -= mod;
}

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

	mp[MX] = 1;

	forn (i, n) {
		cin >> a[i];

		int x = i & 1, y = 1 - x;

		sum(cn[y][MX], 1);

		forn (j, 2 * MX + 5) {
			cn[x][j] = 0;

			if (j - a[i] >= 0) sum(cn[x][j], cn[y][j - a[i]]);
			if (j + a[i] < 2 * MX + 5) sum(cn[x][j], cn[y][j + a[i]]);
		}

		sum(res, cn[x][MX]);
	}

	cout << res << endl;

	return 0;
}