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
typedef vector<ii> vii;

const int MX = 100005;
int n, d[MX], cn, res[MX];
vii adj[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(res, -1, sizeof(res));

	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].emplace_back(b, i);
		adj[b].emplace_back(a, i);
	}

	for (int i = 1; i <= n; i++)
		if (adj[i].size() == 1 && res[adj[i][0].se] == -1)
			res[adj[i][0].se] = cn++;

	for (int i = 1; i < n; i++) {
		if (res[i] == -1) res[i] = cn++;
		cout << res[i] << endl;
	}

	return 0;
}