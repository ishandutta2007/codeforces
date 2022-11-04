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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 10000005;
int n, m, g, r, d[10005];
int dis[MX], sig[MX], ant[MX], q[MX], st, cn, res = -1;

#define num(i,j) ((i) * m + (j))

void insert (int d, int u) {
	int ind = d % MX;

	dis[u] = d;
	
	if (q[ind] != -1) ant[q[ind]] = u;
	sig[u] = q[ind];

	if (q[ind] == -1) cn++;
	q[ind] = u;
}

void erase (int d, int u) {
	int ind = d % MX;

	dis[u] = -1;

	if (sig[u] != -1) ant[sig[u]] = ant[u];
	if (ant[u] != -1) sig[ant[u]] = sig[u];
	
	if (q[ind] == u) q[ind] = sig[u];
	if (q[ind] == -1) cn--;

	sig[u] = ant[u] = -1;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(dis, -1, sizeof(dis));
	memset(sig, -1, sizeof(sig));
	memset(ant, -1, sizeof(ant));
	memset(q, -1, sizeof(q));

	cin >> n >> m;
	forn (i, m) cin >> d[i];
	sort(d, d + m);
	cin >> g >> r;

	dis[num(0, 0)] = 0;
	q[0] = 0;
	cn = 1;

	while (cn && res == -1) {
		while (q[st] != -1 && res == -1) {
			int u = q[st] % m;
			int t = q[st] / m;
			int w = dis[q[st]];

			if (u && t + d[u] - d[u - 1] <= g) {
				int x = t + d[u] - d[u - 1];
				int y = w + d[u] - d[u - 1];

				if (x == g) x = 0, y += r;

				int v = num(x, u - 1);

				if (dis[v] == -1) {
					insert(y, v);
				} else if (dis[v] > y) {
					erase(dis[v], v);
					insert(y, v);
				}
			}

			if (u + 1 < m && t + d[u + 1] - d[u] <= g) {
				int x = t + d[u + 1] - d[u];
				int y = w + d[u + 1] - d[u];

				if (x == g) x = 0, y += r;

				int v = num(x, u + 1);

				if (dis[v] == -1) {
					insert(y, v);
				} else if (dis[v] > y) {
					erase(dis[v], v);
					insert(y, v);
				}
			} else if (u + 1 == m) {
				if (t == 0) w -= r;
				if (res == -1) {
					res = w;
					break;
				}
			}

			q[st] = sig[q[st]];
			if (q[st] == -1) cn--;
		}

		st++;
		if (st == MX) st = 0;
	}

	cout << res << endl;

	return 0;
}