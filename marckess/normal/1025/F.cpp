#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 2005;
int n, q[2 * MX];
ii p[MX];
ll res;

ii operator - (ii a, ii b) { return {a.fi - b.fi, a.se - b.se}; }
ll operator ^ (ii a, ii b) { return ll(a.fi) * b.se - ll(a.se) * b.fi; }
ll cpr (int n) { return n * (n - 1) / 2; }

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	cin >> n;
	forn(i, n) cin >> p[i].fi >> p[i].se;
	iota(q, q+n, 0);

	forn(i, n) {
		sort(q, q+n, [&] (int x, int y) {
			if (x == i) return true;
			if (y == i) return false;
			if ((p[x] < p[i]) != (p[y] < p[i])) return (p[x] < p[i]);
			return ((p[x] - p[i]) ^ (p[y] - p[i])) > 0;
		});
		forn(i, n - 1) q[n+i] = q[i+1];

		for (int j = 1, k = 1; j < n; j++) {
			while (k < j + n - 1 && ((p[q[j]] - p[i]) ^ (p[q[k]] - p[i])) >= 0) k++;
			int cn = k - j - 1;
			res += cpr(cn) * cpr(n - cn - 2);
		}
	}

	cout << res / 2 << endl;

	return 0;
}