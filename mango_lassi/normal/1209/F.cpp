#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int M = 20;
struct Trie {
	int len; // Length of string to this node
	int par[M]; // Parents 2^j steps up from this node
	int c; // Character of this node
	int rem; // Cost mod MOD
	vector<int> kids; // Children

	Trie(int cc, int lenl, int r) {
		c = cc;
		len = lenl;
		rem = ((ll)10*r + c) % MOD;
	}
};
vector<Trie> nodes;

int makeTrie(int c = 0, int p = -1) {
	int i = nodes.size();
	if (p == -1) {
		p = i;
		nodes.emplace_back(c, 0, 0);
	} else {
		nodes.emplace_back(c, nodes[p].len + 1, nodes[p].rem);
		nodes[p].kids.push_back(i);
	}
	nodes[i].par[0] = p;
	for (int j = 1; j < M; ++j) nodes[i].par[j] = nodes[nodes[i].par[j-1]].par[j-1];
	return i;
}
int extend(int i, int v) {
	vector<int> adds;
	while(v > 0) {
		adds.push_back(v % 10);
		v /= 10;
	}
	while(! adds.empty()) {
		int t = adds.back();
		adds.pop_back();

		bool found = false;
		for (auto kid : nodes[i].kids) {
			if (nodes[kid].c == t) {
				i = kid;
				found = true;
				break;
			}
		}
		if (! found) {
			i = makeTrie(t, i);
		}
	}
	return i;
}

bool compare(int a, int b) {
	if (b == -1) return true;
	if (nodes[a].len != nodes[b].len) return nodes[a].len < nodes[b].len;
	for (int j = M-1; j >= 0; --j) {
		if (nodes[a].par[j] != nodes[b].par[j]) {
			a = nodes[a].par[j];
			b = nodes[b].par[j];
		}
	}
	return nodes[a].c < nodes[b].c;
}

const int N = 1e5;
int opt[N]; // Optimal trie node for this node
bool handled[N];
vector<pair<int, int>> conns[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back({b, i+1});
		conns[b].push_back({a, i+1});
	}

	for (int i = 0; i < n; ++i) opt[i] = -1;
	opt[0] = makeTrie(); // Make root node

	priority_queue<pair<int, int>> que;
	que.emplace(0, 0);
	while(! que.empty()) {
		int i = que.top().second;
		que.pop();
		if (handled[i]) continue;
		handled[i] = true;

		for (auto pr : conns[i]) {
			int t = pr.first;
			int off = extend(opt[i], pr.second);
			if (compare(off, opt[t])) {
				opt[t] = off;
				que.push({-nodes[opt[t]].len, t});
			}
		}
	}
	for (int i = 1; i < n; ++i) cout << nodes[opt[i]].rem << '\n';
}