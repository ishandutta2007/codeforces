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

const int MX = 2005;
int n, m, r, c, x, y;
char a[MX][MX];
ii dis[MX][MX];
bitset<MX> vis[MX];

queue<ii> q[2];

ii operator + (ii a, ii b) {
	return {a.fi + b.fi, a.se + b.se};
}

void valid (int ox, int oy, int i, int j, int g, int f) {
	if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || a[i][j] == '*') return;

	dis[i][j] = dis[ox][oy] + ii(g, f);
	vis[i][j] = 1;
	q[g+f].emplace(i, j);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	cin >> r >> c;
	cin >> x >> y;

	for (int i = 0; i < n; i++) cin >> a[i];

	vis[--r][--c] = 1;
	q[0].emplace(r, c);

	while (q[0].size() + q[1].size()) {
		int i, j;
		
		if (q[0].size()) {
			i = q[0].front().fi, j = q[0].front().se;
			q[0].pop();
		} else {
			i = q[1].front().fi, j = q[1].front().se;
			q[1].pop();
		}

		valid(i, j, i+1, j, 0, 0);
		valid(i, j, i-1, j, 0, 0);
		valid(i, j, i, j-1, 1, 0);
		valid(i, j, i, j+1, 0, 1);
	}

	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (vis[i][j] && dis[i][j].fi <= x && dis[i][j].se <= y)
				res++;
	cout << res << endl;

	return 0;
}