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

const int MX = 105;
int n, m, h, a[MX], b[MX], c[MX][MX], res[MX][MX];
bitset<MX> ta, tb;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> h;

	for (int i = 1; i <= m; i++) cin >> b[i];
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> c[i][j];
			res[i][j] = c[i][j];
		}

	for (int k = h; k >= 1; k--)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				if (c[i][j] && a[i] >= k && b[j] >= k && (!ta[i] || !tb[j])) {
					res[i][j] = k;
					ta[i] = 1, tb[j] = 1;
				}
			}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cout << res[i][j] << " ";
		cout << endl;
	}

	return 0;
}