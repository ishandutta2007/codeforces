#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 605, lim = 1e9 + 7;
int n, m, q, u[MX * MX], v[MX * MX], w[MX * MX];
ll dis[2 * MX][2 * MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	
	forn (i, 2 * n)
		forn (j, 2 * n)
			dis[i][j] = 1e18;
	
	forn (i, m) {
		cin >> u[i] >> v[i] >> w[i];
		u[i]--, v[i]--;
		
		dis[u[i]][v[i]] = w[i];
		dis[v[i]][u[i]] = w[i];
		
		dis[u[i] + n][v[i] + n] = w[i];
		dis[v[i] + n][u[i] + n] = w[i];
	}
	
	cin >> q;
	
	while (q--) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		
		dis[u][v + n] = -w;
		dis[v][u + n] = -w;
	}
	
	forn (k, 2 * n)
		forn (u, 2 * n)
			forn (v, 2 * n) {
				ll d = dis[u][k] + dis[k][v];
				if (dis[u][v] > d)
					dis[u][v] = d;
			}
	
	int res = 0;
	forn (i, m)
		res += dis[u[i]][v[i] + n] + w[i] <= 0;
	cout << res << endl;
	
	return 0;
}