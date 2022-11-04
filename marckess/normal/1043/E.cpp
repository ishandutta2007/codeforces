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

const int MX = 300005;
int n, m, x[MX], y[MX], q[MX];
ll res[MX], sx = 0, sy = 0;
int u, v;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
		sy += y[i];
	}

	iota(q, q+n, 1);
	sort(q, q+n, [&] (int i, int j) {
		return y[i] - x[i] > y[j] - x[j];
	});

	for (int i = 0; i < n; i++) {
		int u = q[i];

		sy -= y[u];
		res[u] = x[u] * ll(n - i - 1)
			   + y[u] * ll(i)
			   + sx + sy;
		sx += x[u];
	}

	while (m--) {
		cin >> u >> v;
		int d = min(x[u] + y[v], x[v] + y[u]);
		res[u] -= d;
		res[v] -= d;
	}

	for (int i = 1; i <= n; i++)
		cout << res[i] << " ";
	cout << endl;

	return 0;
}