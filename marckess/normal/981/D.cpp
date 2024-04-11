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

const int MX = 55;
int n, k, dp[MX][MX];
ll a[MX], res = 0;

bool obtRes (int i, int j) {
	if (i == n && j == 0) return 1;
	if (i == n || j == 0) return 0;

	int &r = dp[i][j];
	if (r != -1) return r;
	r = 0;

	ll acu = 0;
	for (int k = i; k < n; k++) {
		acu += a[k];
		if ((acu & res) == res)
			r |= obtRes(k+1, j-1);
	}

	return r;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 60; i >= 0; i--) {
		res |= (1ll << i);
		memset(dp, -1, sizeof(dp));
		if (!obtRes(0, k)) res &= ~(1ll << i);
	}

	cout << res << endl;
	
	return 0;
}