#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 72;
int n, k, x, y, s;
vii pos[MX];
ll dp[MX][MX];
string str;

bool esPos (int i, int j, int a, int b) {
	forn(io_oi,2) {
		for (ii &p : pos[a]) {
			if (!p.fi) {
				// <
				if (p.se < i || p.se > j || p.se == a || p.se == b) return 0;
			} else if (p.fi == 1) {
				// >
				if (i <= p.se && p.se <= j) return 0;
			} else if (p.fi == 2) {
				// <=
				if (p.se < i || p.se > j) return 0;
			} else if (p.fi == 3) {
				// >=
				if (i <= p.se && p.se <= j && p.se != a && p.se != b) return 0;
			} else {
				// =
				if (p.se != a && p.se != b) return 0;
			}
		}

		swap(a, b);
	}

	return 1;
}

ll obtRes (int i, int j) {
	if (j - i == 1) return esPos(i, j, i, j);

	ll &res = dp[i][j];
	if (res != -1) return res;
	res = 0;

	if (esPos(i, j, i, i+1)) res += obtRes(i+2, j);
	if (esPos(i, j, i, j)) res += obtRes(i+1, j-1);
	if (esPos(i, j, j, j-1)) res += obtRes(i, j-2);

	return res; 
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	forn(i,MX) forn(j,MX) dp[i][j] = -1;

	cin >> n >> k;
	forn (_,k) {
		cin >> x >> str >> y;

		if (str == "<") s = 0;
		else if (str == ">") s = 1;
		else if (str == "<=") s = 2;
		else if (str == ">=") s = 3;
		else s = 4;

		pos[x].emplace_back(s, y);
		pos[y].emplace_back(s^1, x);
	}

	cout << obtRes(1, 2*n) << endl;

	return 0;
}