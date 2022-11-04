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

const int MX = 100005;
int n, a[MX], t[MX], sz[MX];
vii adj[MX], res;
ll k, s;

void no () {
	cout << "NO" << endl;
	exit(0);
}

void dfs (int u, int p) {
	sz[u] = 1;

	for (ii &v : adj[u])
		if (v.fi != p) {
			dfs(v.fi, u);

			sz[u] += sz[v.fi];
			t[v.se] = min(sz[v.fi], n - sz[v.fi]);
			s += t[v.se];
		}
}

void dfs (int u, int p, int w, list<int> &ret) {
	vector<list<int>> ch;

	for (ii &v : adj[u])
		if (v.fi != p) {
			ch.pb({});
			dfs(v.fi, u, t[v.se], ch.back());
		}
	
	sort(all(ch), [&] (const auto &a, const auto &b) {
		return a.size() > b.size();
	});

	for (auto &v : ch) {
		while (v.size() + ret.size() >= w && ret.size() && v.size()) {
			res.emplace_back(*ret.begin(), *v.begin());
			ret.erase(ret.begin());
			v.erase(v.begin());
		}

		ret.splice(ret.end(), v);
	}

	if (ret.size() < w) ret.insert(ret.begin(), u);
	else {
		res.emplace_back(*ret.begin(), u);
		ret.erase(ret.begin());
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;

	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].emplace_back(v, i);
		adj[v].emplace_back(u, i);
	}

	dfs(1, 1);

	if (s % 2 != k % 2 || s < k) no();

	int l = 1, r = n, rep = 20;

	while (rep--) {
		int m = (l + r) / 2;
		ll acu = 0;

		forn (i, n - 1) {
			if ((t[i] - m) % 2) acu += min(t[i], m - 1);
			else acu += min(t[i], m);
		}

		if (acu >= k) r = m;
		else l = m;
	}

	s = 0;
	forn (i, n - 1) {
		if ((t[i] - r) % 2) t[i] = min(t[i], r - 1);
		else t[i] = min(t[i], r);
		s += t[i];
	}

	priority_queue<ii> pq;

	forn (i, n - 1) pq.emplace(t[i], i);

	while (s > k && pq.size()) {
		ii u = pq.top();
		pq.pop();

		if (u.fi < 2) continue;

		t[u.se] = u.fi -= 2;
		s -= 2;

		pq.push(u);
	}

	if (s > k) no();

	list<int> kk;
	dfs(1, 1, 0, kk);

	cout << "YES" << endl;
	for (ii &r : res)
		cout << r.fi << " " << r.se << endl;

	return 0;
}