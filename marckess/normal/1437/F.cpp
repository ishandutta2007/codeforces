#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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

const int MX = 5005, mod = 998244353;
int n, a[MX], b[MX], sig[MX];
ll mem[MX][MX][2];

ll dp (int i, int j, int f) {
	if (i == n) return j == n;
	if (j > b[i]) return 0;
	
	ll &res = mem[i][j][f];
	if (res != -1) return res;
	
	if (f)
		return res = (dp(sig[i], j + 1, 0) + (b[i] - j) * dp(i, j + 1, 1)) % mod;
	
	res = dp(i + 1, j, 0) + dp(i, j, 1);
	if (res >= mod)
		res -= mod;
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, n) cin >> a[i];
	sort (a, a + n);
	
	forn (i, n) {
		sig[i] = n;
		forn (j, n) {
			if (2 * a[j] <= a[i]) b[i]++;
			if (2 * a[i] <= a[j]) sig[i] = min(sig[i], j);
		}
	}
	
	memset(mem, -1, sizeof(mem));
	cout << dp(0, 0, 0) % mod << endl;
	
	return 0;
}