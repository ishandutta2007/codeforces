#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int N = 1e5;
vector<int> conns[N];
int par[N];
int dep[N];
int cou[N];

bool check(int i, int p, vector<int>& vals) {
	if (i == p) {
		vals.clear();
		dep[i] = -1;
		cou[i] = -(conns[i].size() >= 3);
	}
	dep[i] = dep[p] + 1;
	cou[i] = cou[p] + (conns[i].size() >= 3);

	bool ans = true;
	if (vals.size() <= dep[i]) vals.push_back(conns[i].size());
	else if (vals[dep[i]] != conns[i].size()) ans = false;

	for (auto t : conns[i]) {
		if (t == p) continue;
		if (! check(t, i, vals)) ans = false;
	}
	return ans;
}

int furthest(int s, int n) {
	for (int i = 0; i < n; ++i) par[i] = -1;
	par[s] = s;
	vector<int> que = {s};
	for (int j = 0; j < n; ++j) {
		int i = que[j];
		for (auto t : conns[i]) {
			if (par[t] == -1) {
				par[t] = i;
				que.push_back(t);
			}
		}
	}
	return que.back();
}

int solve(int n) {
	// Either midpoint of longest trip, or one of its endpoints
	vector<int> vals;
	int a = furthest(0, n);
	int b = furthest(a, n);
	if (check(a, a, vals)) return a+1;
	if (check(b, b, vals)) return b+1;

	vector<int> path = {b};
	while(b != a) {
		b = par[b];
		path.push_back(b);
	}
	if (path.size() % 2 == 0) return -1;

	// Assume some two leaves have an even distance between eachother, and that neither of them works.
	// Then no node works: Any path has to connect to the path between them at some point, and it

	int i = path[path.size() / 2];
	if (check(i, i, vals)) return i+1;

	bool checked_eq = false;
	for (int j = 0; j < n; ++j) {
		if (conns[j].size() == 1 && cou[j] == 0) {
			if (dep[j] == dep[a] && !checked_eq) {
				if (check(j, j, vals)) return j+1;
				check(i, i, vals);
				checked_eq = true;
			} else if (dep[j] < dep[a]) {
				if (check(j, j, vals)) return j+1;
				else return -1;
			}
		}
	}
	return -1;
}
/*
int check(int n) {
	vector<int> vals;
	for (int i = 0; i < n; ++i) {
		if (check(i, i, vals)) return i;
	}
	return -1;
}
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
	}

	int res = solve(n);
	/*
	if (res == -1) {
		int tmp = check(n);
		if (tmp != -1) return 1;
	}
	*/
	cout << res << '\n';
}