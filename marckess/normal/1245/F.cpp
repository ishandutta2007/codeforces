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

int l, r;
ll mem[32][2][2][2];

ll dp (int i, int f, int g, int h) {
	if (i < 0) return 1;
	ll &res = mem[i][f][g][h];
	if (res != -1) return res;
	res = 0;

	int a = bool(r & (1 << i));
	int b = bool(l & (1 << i));

	for (int x = 0; x < 2; x++)
		for (int y = 0; y < 2; y++) {
			if (x && y) continue;
			if (x > a && !f) continue;
			if (y < b && !g) continue;
			if (x < y && !h) continue;

			res += dp(
				i - 1, 
				x < a || f,
				y > b || g,
				x > y || h
			);
		}

	return res;
}

int solve () {
	cin >> l >> r;
	memset(mem, -1, sizeof(mem));
	cout << 2 * dp(30, 0, 0, 0) - (!l) << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}