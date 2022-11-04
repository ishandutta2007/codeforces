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
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 1005;
int n, m, tob[MX][MX], tor[MX][MX];
char a[MX][MX];
ll res = 0;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	forn(i, n) forn(j, m) cin >> a[i][j];

	forn(i, n) {
		for (int j = m - 1; j + 1; j--)
			if (a[i][j] == a[i][j+1])
				tor[i][j] = tor[i][j+1];
			else
				tor[i][j] = j + 1;
	}

	forn(j, m) {
		for (int i = n - 1; i + 1; i--)
			if (a[i][j] == a[i+1][j])
				tob[i][j] = tob[i+1][j];
			else
				tob[i][j] = i + 1;
	}

	forn (i, n) forn(j, m) {
		int f = 1, tam = tob[i][j] - i, it = i;
		forn(k, 2) {
			it = tob[it][j];
			if (it >= n) {
				f = 0;
				break;
			}
			if (tob[it][j] - it != tam) {
				if (!k || tob[it][j] - it < tam) {
					f = 0;
					break;
				}
			}
		}
		if (f) {
			int mn = m;
			forn(k, 3 * tam)
				mn = min(mn, tor[i+k][j] - j);
			res += mn;
		}
	}

	cout << res << endl;

	return 0;
}