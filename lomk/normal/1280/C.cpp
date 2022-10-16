/*input
2
3
1 2 3
3 2 4
2 4 3
4 5 6
5 6 5
2
1 2 1
1 3 2
1 4 3

*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define mp make_pair
#define fi first
#define se second
#define __builtin_popcount __builtin_popcountll
#define int long long
#define loop(i,l,r) for(int i=(l); i<=(r); i++)
#define rloop(i,l,r) for(int i=(l); i>=(r); i--)
#define bit(x,y) ((x>>y)&1LL)
const int N = 2e5 + 5;
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &a) {
	return os << '(' << a.first << ", " << a.second << ')';
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &a) {
	os << '[';
	for (unsigned int i = 0; i < a.size(); i++)
		os << a[i] << (i < a.size() - 1 ? ", " : "");
	os << ']';
	return os;
}

int n;
vector<vector<pair<int, int> > > a(N);

class minSolverX {
public:
	int ans = 0;
	int dfs(int u, int p) {
		vector<int> all;
		for (auto v : a[u]) {
			if (v.fi == p) continue;
			auto rec = dfs(v.fi, u);
			if (rec != -1) all.push_back(rec + v.se);
		}
		for (auto it : all) ans += it;
		if (all.size() % 2 == 0) {
			return 0;
		}
		else {
			return -1;
		}
	}
	int solve() {
		ans = 0;
		dfs(1, 1);
		return ans;
	}
} minSolver;

class maxSolverX {
public:
	int ans = 0;
	int child[N];
	void dfs(int u, int p) {
		child[u] = 1;
		for (auto v : a[u]) {
			if (v.fi == p) continue;
			dfs(v.fi, u);
			child[u] += child[v.fi];
		}
	}
	int findcen(int u, int p) {
		for (auto v : a[u]) {
			if (v.fi == p) continue;
			if (child[v.fi] > n / 2) return findcen(v.fi, u);
		}
		return u;
	}
	void solve(int u, int p, int depth) {
		ans += depth;
		for (auto v : a[u]) {
			if (v.fi == p) continue;
			solve(v.fi, u, depth + v.se);
		}
	}
	int solve() {
		ans = 0;
		dfs(1, 1);
		int cen = findcen(1, 1);
		solve(cen, cen, 0);
		return ans;
	}
} maxSolver;

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> n; n *= 2;
		a.assign(n + 5, vector<pair<int, int> >());
		loop(i, 1, n - 1) {
			int u, v, c;
			cin >> u >> v >> c;
			a[u].push_back(mp(v, c));
			a[v].push_back(mp(u, c));
		}
		cout << minSolver.solve() << sp << maxSolver.solve() << endl;
	}

}