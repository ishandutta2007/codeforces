#include <iostream>
#include <vector>
#include <utility>
#include <set>
using namespace std;
typedef long long ll;
const int INF = (int)1e9 + 7;

const ll N = 5 * (ll)1e5;
const ll M = 5 * (ll)1e5;
const int E = 1e6;
const ll H = 20;
int comp[N];
int siz[N];

int compress(int i) {
	if (comp[i] != i) comp[i] = compress(comp[i]);
	return comp[i];
}

bool join(int a, int b) {
	a = compress(a);
	b = compress(b);
	if (a == b) return false;
	if (siz[a] < siz[b]) swap(a, b);
	siz[a] += siz[b];
	comp[b] = a;
	return true;
}

int edge_a[E];
int edge_b[E];
int edge_w[E];
vector<int> oth_conns[N];
vector<int> conns[N];

int getOth(int ei, int a) {
	if (edge_a[ei] != a) return edge_a[ei];
	return edge_b[ei];
}

int step[N];
int bridges(int i, int pe = -1, int s = 1) {
	step[i] = s;

	int res = s;
	for (auto ei : conns[i]) {
		if (ei == pe) continue;
		int t = getOth(ei, i);
		if (step[t] == 0) {
			int sub = bridges(t, ei, s+1);
			if (sub > s && edge_w[ei] == INF) {
				return -INF;
			}
			res = min(sub, res);
		} else {
			res = min(res, step[t]);
		}
	}
	for (auto ei : oth_conns[i]) {
		if (ei == pe) continue;
		int t = getOth(ei, i);
		if (step[t] == 0) {
			int sub = bridges(t, ei, s+1);
			if (sub > s && edge_w[ei] == INF) {
				return -INF;
			}
			res = min(sub, res);
		} else {
			res = min(res, step[t]);
		}
	}
	return res;
}

vector<int> lasts[N];
ll result = 0;

void modPush(set<pair<int, int>>& a, pair<int, int> v) {
	auto it = a.find(v);
	if (it != a.end()) {
		a.erase(it);
	} else {
		a.insert(v);
	}
}

void combine(set<pair<int, int>>& a, set<pair<int, int>>& b) {
	if(a.size() < b.size()) swap(a, b);
	for (auto it : b) {
		modPush(a, it);
	}
	b.clear();
}

set<pair<int, int>> dfs(int i, int p = -1) {
	set<pair<int, int>> ret;

	for (auto ei : conns[i]) {
		int t = getOth(ei, i);
		if (t == p) continue;
		auto sub = dfs(t, i);
		combine(ret, sub);
	}
	
	for (auto ei : oth_conns[i]) {
		ll w = edge_w[ei];
		modPush(ret, {w, ei});
	}
	if (! ret.empty()) {
		result += (*ret.begin()).first;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k, m;
	cin >> n >> k >> m;

	for (int i = 0; i < n; ++i) {
		comp[i] = i;
		siz[i] = 1;
	}

	for (int i = 0; i < k; ++i) {
		cin >> edge_a[i] >> edge_b[i];
		--edge_a[i];
		--edge_b[i];
		edge_w[i] = INF;
		
		conns[edge_a[i]].push_back(i);
		conns[edge_b[i]].push_back(i);
		
		join(edge_a[i], edge_b[i]);
	}

	for (int i = k; i < k+m; ++i) {
		cin >> edge_a[i] >> edge_b[i] >> edge_w[i];
		--edge_a[i];
		--edge_b[i];
		
		oth_conns[edge_a[i]].push_back(i);
		oth_conns[edge_b[i]].push_back(i);

		if (join(edge_a[i], edge_b[i])) {
			conns[edge_a[i]].push_back(i);
			conns[edge_b[i]].push_back(i);
			result -= edge_w[i];
		}
	}
	// -1 if one of our edges is a bridge in the graph.
	if (bridges(0) == -INF) {
		cout << "-1\n";
	} else {
		dfs(0);
		cout << result << '\n';
	}
}

// We are only llerested in competing edges that form a minimum spanning tree.
// Also, we need some of their edges to have our competing spanning tree.

// Starting from our tree's leaves, all of the leaf edges must cost <= than all
// of the edges adjanced to them.

// The maximum price for a edge in our spanning tree is the same as the price
// for any edge that is connecting the components that that edge divides our
// components llo.

// Our spanning tree
// o   o   o
//  \ / \ /
//   X o X
//  / \|/ \
// o   o - o

// Their spanning tree
// o - o - o
//     | 
//     o
//     |
// o - o - o

// How do we find these values?