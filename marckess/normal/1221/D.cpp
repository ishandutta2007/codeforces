#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 300005;
int n, a[MX], b[MX];
ll mem[MX][10];

ll dp (int i, int j) {
	if (i > n) return 0;
	ll &res = mem[i][j];
	if (res != -1) return res;
	res = 2e18;
	for (int k = 0; k < 10; k++)
		if (a[i-1] + j != a[i] + k)
			res = min(res, dp(i+1, k) + 1ll * k * b[i]);
	return res;
}

void solve () {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		memset(mem[i], -1, sizeof(mem[i]));
	}

	cout << dp(1, 0) << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int q;
	cin >> q;
	while (q--)
		solve();

	return 0;
}