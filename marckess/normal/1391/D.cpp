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

const int MX = 1000005;
int n, m, a[MX][3], f;
int mem[MX][1 << 3];

int dp (int i, int mk) {
	if (i == n) return 0;

	int &res = mem[i][mk];
	if (res != -1) return res;
	res = n * m;

	int p = a[i][0], mp = 0;

	for (int j = 1; j < m; j++) {
		int cn = bool(mk & (1 << j)) + bool(mk & (1 << j - 1)) + bool(mp & (1 << j - 1));
		
		if (cn & 1) p += a[i][j];
		else {
			mp |= 1 << j;
			p += 1 - a[i][j];
		}
	}

	res = min(p + dp(i + 1, mp), (m - p) + dp(i + 1, ((1 << m) - 1) ^ mp));

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(mem, -1, sizeof(mem));
	
	cin >> n >> m;

	if (n < m) {
		f = 1;
		swap(n, m);
	} 

	if (3 < m) {
		cout << -1 << endl;
		return 0;
	}

	if (f) {
		forn (j, m) forn (i, n) {
			char c;
			cin >> c;
			a[i][j] = c - '0';
		}
	} else {
		forn (i, n) forn (j, m) {
			char c;
			cin >> c;
			a[i][j] = c - '0';
		}
	}

	int res = n * m;

	for (int mk = 0; mk < (1 << m); mk++) {
		int x = 0;

		forn (j, m) x += a[0][j] ^ bool(mk & (1 << j));

		res = min(res, dp(1, mk) + x);
	}

	cout << res << endl;

	return 0;
}