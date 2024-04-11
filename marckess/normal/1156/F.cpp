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

const int MX = 5005, mod = 998244353;
int n;
ll in[MX], dp[MX][MX][2];
vi a;
map<int, int> mp;

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p >>= 1;
	}
	return res;
}

ll obtRes (int i, int j, int f, int tot) {
	if (i == a.size()) return 0;
	ll &res = dp[i][j][f];
	if (res != -1) return res;
	if (f) return res = (a[i] - 1 + obtRes(i+1, j, 0, tot)) * in[tot] % mod;
	return res = (a[i] * obtRes(i, j + a[i] - 1, 1, tot - 1) + obtRes(i+1, j + a[i], 0, tot)) % mod;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(dp, -1, sizeof(dp));

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		mp[a]++;
	}

	a.pb(1);
	for (ii x : mp) a.pb(x.se);
	for (int i = 1; i <= n; i++) in[i] = pot(i, mod - 2);

	cout << obtRes(0, 0, 1, n) << endl;

	return 0;
}