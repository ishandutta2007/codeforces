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

const int MX = 100005;
int n, m, a[10][MX], f[10][MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			f[i][a[i][j]] = j;
		}

	ll res = 0, acu = 0;

	for (int j = 0; j < n; j++) {
		bool g = j + 1 < n;
		acu++;

		for (int i = 1; i < m; i++)
			g &= a[i][f[i][a[0][j]]+1] == a[0][j+1];

		if (!g) {
			res += acu * (acu + 1) / 2;
			acu = 0;
		}
	}

	cout << res << endl;

	return 0;
}