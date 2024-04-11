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

const int MX = 10005;
int n, l, r, a[MX], b[MX];
bitset<MX> dp[MX][2], bs;
vi x, y;

bool esPos (int m) {
	int acu = 0;
	forn (i, m) acu += x[n - i - 1];

	for (int i = r; i - acu >= l; i--)
		if (dp[n - m - 1][1][i - acu])
			return 1;

	return 0;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> l >> r;
	forn (i, n) cin >> a[i];
	forn (i, n) cin >> b[i];

	forn (i, n) {
		if (b[i]) x.pb(a[i]);
		else y.pb(a[i]);
	}

	if (!x.size()) {
		cout << 0 << endl;
		return 0;
	}

	sort(all(x), greater<int>());

	bs[0] = 1;
	forn (i, y.size())
		bs |= bs << y[i];

	dp[0][0] = bs << x[0];
	dp[0][1] = bs;

	n = x.size();
	forn (i, n - 1) {
		dp[i + 1][0] = dp[i][0] << x[i + 1];
		dp[i + 1][1] = dp[i][0] | dp[i][1] | (dp[i][1] << x[i + 1]);
	}

	int i = 0, j = n - 1, rep = 15;
	while (rep--) {
		int m = (i + j + 1) / 2;
		if (esPos(m)) i = m;
		else j = m;
	}

	if (esPos(i)) cout << i + 1 << endl;
	else cout << 0 << endl;

	return 0;
}