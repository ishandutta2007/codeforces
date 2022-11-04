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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 2005;
const ll inf = 1e18;
int n, k, l[MX], r[MX], a[MX];
ll mem[MX][MX];

ll dp (int i, int j, int x) {
	if (i == n) return 0;
	
	ll &res = mem[i][j];
	if (res != -1) return res;
	res = inf;
	
	int dis = r[i] - l[i] + 1;
	int nec = x >= a[i] ? 1 : (a[i] - x + k - 1) / k + 1;
	int ret = x >= a[i] ? x - a[i] : k - (a[i] - x) % k;
	if (ret == k) ret -= k;
	
	if (nec <= dis) {
		res = min(res, dp(i + 1, j, ret) + a[i]);
		if (nec < dis || (nec == dis && r[i] < l[i + 1]))
			res = min(res, dp(i + 1, i + 1, k) + a[i] + ret);
	}
	
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	forn (i, n) cin >> l[i] >> r[i] >> a[i];
	
	memset(mem, -1, sizeof(mem));
	ll res = dp(0, 0, k);
	
	if (res == inf) cout << -1 << endl;
	else cout << res << endl;
	
	return 0;
}