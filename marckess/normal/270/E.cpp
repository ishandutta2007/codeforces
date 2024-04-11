#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, m, a[MX], b[MX], c[MX], res[MX];
ll d[MX];
vi adj[MX];

bitset<MX> bs;
queue<int> q;

void obtRes () {
	q.push(1);
	bs[1] = 1;

	while (q.size()) {
		int u = q.front(), v;
		q.pop();

		for (int i : adj[u]) {
			if (u == a[i]) {
				v = b[i];
			} else {
				v = a[i];
				if (!bs[v]) res[i] = 1;
			}

			if (bs[v] || v == 1 || v == n) continue;
			d[v] -= c[i];

			if (!d[v]) {
				q.push(v);
				bs[v] = 1;
			}
		}
	}

	assert(bs.count() == n-1);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i] >> c[i];
		d[a[i]] += c[i];
		d[b[i]] += c[i];
		adj[a[i]].push_back(i);
		adj[b[i]].push_back(i);
	}

	for (int i = 2; i < n; i++)
		d[i] /= 2;

	obtRes();
	for (int i = 0; i < m; i++)
		cout << res[i] << endl;

	return 0;
}