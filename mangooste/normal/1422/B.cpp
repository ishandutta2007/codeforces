#include <bits/stdc++.h>

using namespace std;

string to_string(string s) {
	return "\"" + s + "\"";
}

string to_string(bool b) {
	return b ? "true" : "false";
}

template<class T>
string to_string(T v);

template<class A, class B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template<class T>
string to_string(T v) {
	string s = "{";
	string sep = "";
	for (auto x : v) {
		s += sep;
		sep = ", ";
		s += to_string(x);
	}
	return s + "}";
}

void debug_out() { cerr << endl; }
template<class Head, class... Tail>
void debug_out(Head head, Tail... tail) {
	cerr << ' ' << to_string(head);
	debug_out(tail...);
}

#ifdef LOCAL
#define debug(...) cerr << '[' << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

int n, m;
vector<vector<int>> a;
vector<vector<int>> g;
vector<char> used;

inline int get_num(int i, int j) {
	return i * m + j;
}

void dfs(int v, vector<int> &comp) {
	used[v] = 1;
	comp.push_back(v);
	for (auto u : g[v])
		if (!used[u])
			dfs(u, comp);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		a.clear();
		g.clear();
		used.clear();

		cin >> n >> m;
		a.resize(n, vector<int>(m));
		for (auto &xs : a)
			for (auto &x : xs)
				cin >> x;

		g.resize(n * m);
		used.resize(n * m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				// debug(i, j);
				// debug(get_num(i, j), get_num(n - 1 - i, j));
				g[get_num(i, j)].push_back(get_num(n - 1 - i, j));
				g[get_num(i, j)].push_back(get_num(i, m - 1 - j));
			}

		// debug(g);

		long long ans = 0;
		for (int i = 0; i < n * m; i++)
			if (!used[i]) {
				vector<int> comp;
				dfs(i, comp);
				vector<int> els;
				for (auto x : comp) {
					int i = x / m;
					int j = x % m;
					els.push_back(a[i][j]);
				}
				sort(els.begin(), els.end());
				int mid = (int) els.size() / 2;
				for (int i = 0; i < (int) els.size(); i++)
					ans += abs(els[i] - els[mid]);
			}

		cout << ans << '\n';
	}
}