#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

typedef long long int64;
typedef long double ld;

template <class T> bool bmin(T& a, T b) { return a > b ? (a = b, true) : false; }
template <class T> bool bmax(T& a, T b) { return a < b ? (a = b, true) : false; }

const int64 INF64 = 1e18;
const int INF = 1e9;

using namespace std;

vector <vector <int>> G;
vector <int> c;

vector <int> dfs(int v, int pr) {
	vector <int> res;
	for (auto u : G[v]) {
		if (u != pr) {
			vector <int> cur = dfs(u, v);
			for (auto i : cur) {
				res.push_back(i);
			}
		}
	}
	if (c[v] > res.size()) {
		cout << "NO\n";
		exit(0);
	}
	res.insert(res.begin() + c[v], v);
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	G.resize(n);
	c.resize(n);
	int root = -1;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p >> c[i];
		if (p == 0) {
			root = i;
		} else {
			p--;
			G[i].push_back(p);
			G[p].push_back(i);
		}
	}

	vector <int> cur = dfs(root, root);
	vector <int> res(n);
	for (int i = 0; i < n; i++) {
		res[cur[i]] = i + 1;
	}

	cout << "YES\n";
	for (auto i : res) {
		cout << i << ' ';
	}
	cout << '\n';
}