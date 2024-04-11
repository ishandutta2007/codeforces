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

const int MX = 200005;
int n, m, w[MX], x[MX], y[MX], cn[MX];
bitset<MX> bs, g;
vi pos[MX], res;
queue<int> q;

void solve () {
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> w[i];

	for (int i = 1; i <= m; i++) {
		cin >> x[i] >> y[i];
		pos[x[i]].pb(i);
		pos[y[i]].pb(i);
		cn[x[i]]++;
		cn[y[i]]++;
	}

	for (int i = 1; i <= n; i++)
		if (cn[i] <= w[i]) {
			q.push(i);
			g[i] = 1;
		}

	while (q.size()) {
		int u = q.front();
		q.pop();

		for (int i : pos[u])
			if (!bs[i]) {
				res.pb(i);
				bs[i] = 1;

				cn[x[i]]--;
				if (!g[x[i]] && cn[x[i]] <= w[x[i]]) {
					g[x[i]] = 1;
					q.push(x[i]);
				}

				cn[y[i]]--;
				if (!g[y[i]] && cn[y[i]] <= w[y[i]]) {
					g[y[i]] = 1;
					q.push(y[i]);
				}
			}
	}

	if (res.size() == m) {
		cout << "ALIVE" << endl;
		reverse(all(res));
		for (int r : res)
			cout << r << " ";
		cout << endl;
	} else {
		cout << "DEAD" << endl;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t = 1;
	//cin >> t;
	while (t--)
		solve();	

	return 0;
}