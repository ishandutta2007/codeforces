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

int n, t, mem[105][1005];
vi pos[105];

int dp (int i, int j) {
	if (i == t) return 0;
	if (!j) return 0;

	int &res = mem[i][j];
	if (res != -1) return res;
	res = dp(i + 1, min(2 * j, n));

	int acu = 0;
	
	forn (k, min(j, int(pos[i].size()))) {
		acu += pos[i][k];
		res = max(res, acu + dp(i + 1, min(2 * (j - k - 1), n)));
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(mem, -1, sizeof(mem));

	cin >> n >> t;

	forn (i, n) {
		int x, q;
		cin >> x >> q;
		x = t - x;
		pos[x].pb(q);
	}

	forn (i, t) sort(all(pos[i]), greater<int>());

	cout << dp(0, 1) << endl;

	return 0;
}