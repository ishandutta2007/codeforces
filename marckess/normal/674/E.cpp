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

const int MX = 500005, lim = 60;
int q, n = 1, p[MX];
ld dp[MX][lim];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(8);

	forn (i, MX) forn (j, lim) dp[i][j] = 1;

	cin >> q;
	while (q--) {
		int op, v;
		cin >> op >> v;

		if (op == 1) {
			p[++n] = v;

			ld aux = dp[v][0];
			dp[v][0] *= 0.5;

			int i = 1;
			while (v && i < lim) {
				ld t = dp[p[v]][i];
				dp[p[v]][i] *= (1 + dp[v][i - 1]) / (1 + aux);
				aux = t;
				v = p[v];
				i++;
			}
		} else {
			ld res = lim;
			
			forn (j, lim)
				res -= dp[v][j];
			
			cout << res << endl;
		}
	}

	return 0;
}