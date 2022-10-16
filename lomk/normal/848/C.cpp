/*input
7 6
1 2 3 1 3 2 1
2 3 7
2 1 3
1 7 2
1 3 2
2 1 6
2 5 7



7 6
1 2 3 1 3 2 1
2 3 7
2 1 3
1 7 2
1 3 2
2 1 6
2 5 7



*/
#ifdef UncleGrandpa
#include <prettyprint.hpp>
#endif
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define int long long
#define loop(i,l,r) for(int i=(l); i<=(r); i++)
#define rloop(i,l,r) for(int i=(l); i>=(r); i--)
#define debug(x...) {cout << "[" << #x << "] ="; _co(x);}
void _co() {cout << endl;}
template<typename T, typename... Ts> void _co(const T& value, const Ts&... values) {cout << ' ' << value; _co(values...);}
template<typename T, typename... Ts> void co(const T& value, const Ts&... values) {cout << "deb: " << value; _co(values...);}
#ifdef UncleGrandpa
const int N = 105;
#else
const int N = 1e5 + 5;
#endif
#define prev prev__

struct BIT2Dx {
	const int INF = 2e9;
	int n;
	vector<vector<int> > nodes, f;
	void update(bool real, int u, int v, int val) {
		if (!real) {
			for (int x = u; x <= n; x += x & -x) nodes[x].push_back(v);
			return;
		}
		for (int x = u; x <= n; x += x & -x)
			for (int y = lower_bound(nodes[x].begin(), nodes[x].end(), v) - nodes[x].begin() + 1; y <= nodes[x].size(); y += y & -y)
				f[x][y] += val;
	}
	int get(bool real, int u, int v) {
		if (!real) {
			for (int x = u; x > 0; x -= x & -x) nodes[x].push_back(v);
			return 0;
		}
		int res = 0;
		for (int x = u; x > 0; x -= x & -x)
			for (int y = upper_bound(nodes[x].begin(), nodes[x].end(), v) - nodes[x].begin(); y > 0; y -= y & -y)
				res += f[x][y];
		return res;
	}
	void init(int _n) {
		n = _n;
		f.assign(n + 5, vector<int>());
		nodes.assign(n + 5, vector<int>());
	}
	void normalize() {
		loop(i, 1, n) {
			sort(nodes[i].begin(), nodes[i].end());
			nodes[i].push_back(INF);
			f[i].resize(nodes[i].size() + 3);
		}
	}
} BIT;

struct Solver {
	bool real; int n, q;
	array<int, N> a;
	vector<tuple<int, int, int> > query;
	int prev[N], nxt[N], last[N];
	set<int> alpos[N];
	vector<int> ans;

	void modify(int i, int sign) {
		if (i == n + 1 || i == 0 || prev[i] == 0) return;
		// debug(a[i], prev[i], i, sign * (i - prev[i]));
		BIT.update(real, prev[i], i, sign * (i - prev[i]));
	}

	void update(int i, int val) {
		modify(i, -1); modify(nxt[i], -1);
		nxt[prev[i]] = nxt[i];
		prev[nxt[i]] = prev[i];
		modify(nxt[i], 1);
		alpos[a[i]].erase(i);
		prev[i] = 0, nxt[i] = n + 1;
		a[i] = val;

		// debug("X");
		auto it = alpos[val].upper_bound(i);
		if (it != alpos[val].end()) {
			modify(*it, -1);
			prev[*it] = i;
			nxt[i] = *it;
			modify(*it, 1);
		}
		if (it != alpos[val].begin()) {
			--it; nxt[*it] = i;
			prev[i] = *it;
		}
		alpos[val].insert(i);
		modify(i, 1);
	}

	int get(int l, int r) {
		return BIT.get(real, n, r) - BIT.get(real, l - 1, r);
	}

	Solver(bool _real, int _n, int _q, array<int, N> _a, vector<tuple<int, int, int> > _query):
		real(_real), n(_n), q(_q), a(_a), query(_query) {
		fill(last, last + N, 0);
		loop(i, 1, n) {
			prev[i] = last[a[i]];
			last[a[i]] = i;
		}

		fill(last, last + N, n + 1);
		rloop(i, n, 1) {
			nxt[i] = last[a[i]];
			last[a[i]] = i;
		}

		loop(i, 1, n) alpos[a[i]].insert(i);

// (prev[i],i) i-prev[i]
		loop(i, 1, n) {
			if (prev[i] != 0) modify(i, 1);
		}

		for (auto &curQ : query) {
			auto &[type, fi, se] = curQ;
			if (type == 1) update(fi, se);
			else ans.push_back(get(fi, se));
		}
	};
};

array<int, N> a;
vector<tuple<int, int, int> > query;
signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, q;
	cin >> n >> q; BIT.init(n);

	loop(i, 1, n) cin >> a[i];
	loop(i, 1, q) {
		int x, y, z;
		cin >> x >> y >> z;
		auto cur = make_tuple(x, y, z);
		query.push_back(cur);
	}
	Solver psolve(0, n, q, a, query);
	BIT.normalize();
	Solver solve(1, n, q, a, query);
	for (auto it : solve.ans) cout << it << endl;
}