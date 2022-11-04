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

const int MX = 1005;
int n, x;
ld adj[MX][MX], p, res[MX], no[MX], acu[MX];
bitset<MX> bs;

bool igual (ld a, ld b) { return fabs(a-b) < 1e-12; }
bool le (ld a, ld b) { return a < b && !igual(a, b); }

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	fill(res, res+MX, -1);
	fill(no, no+MX, 1);

	scanf("%d", &n);
	forn(i,n) forn(j,n) {
		scanf("%d", &x);
		adj[i][j] = ld(x) / 100;
	}

	bs[n-1] = 1;
	res[n-1] = 0;
	for (int i = 0; i < n-1; i++)
		if (adj[i][n-1]) {
			acu[i] += no[i] * adj[i][n-1] * (res[n-1] + 1);
			no[i] *= 1 - adj[i][n-1];
			res[i] = (acu[i] + no[i]) / (1 - no[i]);
		}

	for (int _ = 1; _ < n; _++) {
		int u = 0;
		for (int i = 0; i < n; i++)
			if (!bs[i] && res[i] != -1 && (res[u] == -1 || le(res[i], res[u])))
				u = i;
		
		bs[u] = 1;
		for (int v = 0; v < n-1; v++)
			if (!bs[v] && adj[v][u]) {
				acu[v] += no[v] * adj[v][u] * (res[u] + 1);
				no[v] *= 1 - adj[v][u];
				res[v] = (acu[v] + no[v]) / (1 - no[v]);
			}
	}

	cout << fixed << setprecision(10) << res[0] << endl;

	return 0;
}