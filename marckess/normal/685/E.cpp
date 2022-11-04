#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = (a); i <= (b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 200005;
int n, m, q, dis[1005][1005];
int u[MX], v[MX];
int l[MX], r[MX], s[MX], t[MX], res[MX];
vi pos[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> q;
	
	for (int i = 1; i <= m; i++)
		cin >> u[i] >> v[i];

	for (int i = 1; i <= q; i++) {
		cin >> l[i] >> r[i] >> s[i] >> t[i];
		pos[r[i]].pb(i);
	}

	for (int i = 1; i <= m; i++) {
		dis[u[i]][v[i]] = dis[v[i]][u[i]] = i;

		for (int j = 1; j <= n; j++)
			if (j != u[i] && j != v[i])
				dis[j][u[i]] = dis[j][v[i]] = max(dis[j][u[i]], dis[j][v[i]]);

		for (int j : pos[i])
			res[j] = dis[s[j]][t[j]] >= l[j];
	}

	for (int i = 1; i <= q; i++) {
		if (res[i]) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}