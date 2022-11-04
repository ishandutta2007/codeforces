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
int n, a[MX], bs[10 * MX], res = 1e9, vis[10 * MX];
int dis[MX], from[MX];
vi p, pos[10 * MX];
queue<int> q;
set<int> st;

int f (int n, int i) {
	int x = 1;
	while (n > 1) {
		int p = bs[n], pw = 0;
		while (n % p == 0) {
			n /= p;
			pw++;
		}
		if (pw % 2) {
			pos[p].pb(i);
			x *= p;
		}
	}
	return x;
}

void clear () {
	memset(dis, -1, sizeof(dis));
	for (int x : p)
		vis[x] = 0;
}

int bfs () {
	int res = 1e9;

	while (q.size()) {
		int u = q.front();
		int x = a[u];
		q.pop();

		forn (_, 2) {
			if (x < 2) break;

			if (!vis[bs[x]]) {
				vis[bs[x]] = 1;

				for (int v : pos[bs[x]])
					if (dis[v] == -1) {
						dis[v] = dis[u] + 1;
						from[v] = from[u];
						q.push(v);
					} else if (from[v] != from[u]) {
						res = min(res, dis[u] + dis[v] + 2);
					}
			}

			 x /= bs[x];
		}
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	for (int i = 2; i < 10 * MX; i++)
		if (!bs[i]) {
			p.pb(i);
			for (int j = i; j < 10 * MX; j += i)
				bs[j] = i;
		}

	cin >> n;
	forn (i, n) {
		cin >> a[i];
		a[i] = f(a[i], i);

		if (a[i] == 1) {
			cout << 1 << endl;
			return 0;
		}
	}

	forn (i, n) {
		if (st.count(a[i])) {
			cout << 2 << endl;
			return 0;
		}
		st.insert(a[i]);
	}

	clear();
	forn (i, n) if (a[i] == bs[a[i]]) {
		q.push(i);
		dis[i] = 0;
		from[i] = i;
	}

	res = min(res, bfs());

	for (int x : p)
		if (x < 1000 && pos[x].size()) {
			clear();

			for (int i : pos[x])
				if (a[i] != x) {
					q.push(i);
					dis[i] = 0;
					from[i] = i;
				}

			vis[x] = 1;
			res = min(res, bfs());
		}

	if (res == 1e9) cout << -1 << endl;
	else cout << res << endl;

	return 0;
}