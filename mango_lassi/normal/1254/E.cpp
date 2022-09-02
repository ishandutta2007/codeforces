#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int N = 5 * (int)1e5;
vector<int> conns[N];
int need[N]; // What must end up here
int tar[N]; // Where this must end up

int siz[N]; // Size of subtree
int ind[N]; // DFS index

int in[N]; // What must go in to this subtree
int out[N]; // What must come out of this subtree

int nxt[N];

ll fact[N];

void dfs(int i, int p, int& j) {
	ind[i] = j;
	siz[i] = 1;
	++j;

	for (auto t : conns[i]) {
		if (t != p) {
			dfs(t, i, j);
			siz[i] += siz[t];
		}
	}
}

bool cont(int i, int j) {
	return j == -1 || (ind[i] <= ind[j] && ind[j] < ind[i] + siz[i]);
}

bool build(int i, int p) {
	in[i] = -1;
	out[i] = -1;

	for (auto t : conns[i]) {
		if (t == p) continue;
		if (! build(t, i)) return false;

		if (out[t] != -1 && !cont(i, tar[out[t]])) {
			if (out[i] != -1) return false;
			out[i] = out[t];
		}
		if (!cont(i, in[t])) {
			if (in[i] != -1) return false;
			in[i] = in[t];
		}
	}

	if (!cont(i, tar[i])) {
		if (out[i] != -1) return false;
		out[i] = i;
	}
	if (!cont(i, need[i])) {
		if (in[i] != -1) return false;
		in[i] = need[i];
	}

	return true;
}

bool check(int i) {
	if (i == -1) return false;
	int j = i;
	do {
		int x = nxt[j];
		nxt[j] = -1;
		j = x;
	} while(j != -1 && j != i);
	return j == i;
}

ll solve(int i, int p) {
	ll res = 1;
	for (auto t : conns[i]) {
		if (t != p) res = (res * solve(t, i)) % MOD;
	}

	// Find forced order of edges
	int must = 0;
	if (out[i] != -1) {
		++must;
		nxt[out[i]] = in[i];
	}
	if (need[i] != -1 && in[i] == need[i]) ++must;
	for (auto t : conns[i]) {
		if (t == p) continue;
		if (in[t] != -1) {
			++must;
			nxt[in[t]] = out[t];
		}
		if (need[i] != -1 && out[t] == need[i]) ++must;
	}

	// Check for cycles
	int cou = 0;
	for (int j = i; j != -1; j = nxt[j]) {
		if (j == need[i] && cou < conns[i].size()) res = 0;
		++cou;
	}

	if (check(out[i])) res = 0;
	for (auto t : conns[i]) {
		if (t != p && check(in[t])) res = 0;
	}

	int k = (int)conns[i].size() - must;
	if (k >= 0) res = (res * fact[k]) % MOD;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	fact[0] = 1;
	for (int i = 1; i < n; ++i) fact[i] = i * fact[i-1] % MOD;

	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
	}
	for (int i = 0; i < n; ++i) {
		tar[i] = -1;
		nxt[i] = -1;
	}
	for (int i = 0; i < n; ++i) {
		cin >> need[i];
		--need[i];
		if (need[i] != -1) tar[need[i]] = i;
	}

	/*
	7
	1 2
	1 3
	2 5
	2 7
	3 4
	4 6
	7 0 0 0 0 3 0

	   1
	 2   3
	5 7  4
	     6

	4 1 1, -1 -1
	6 0 1, -1 6
	1 3 6, -1 -1
	5 -1 1, 2 5
	3 1 1, 2 -1
	2 1 1, -1 -1
	0 2 12, -1 -1
	*/

	int id = 0;
	dfs(0, 0, id);
	bool fail = !build(0, 0);
	ll res = fail ? 0 : solve(0, 0);
	cout << res << endl;
}