#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure for storing positive integers, decrementing them by one and returning maximum.
// Initialization in O(max-val), O(1) per query.
class DecMax {
	private:
		vector<int> cou;
	public:
		void init(int v) {
			if (v < 0) return;
			if (v >= cou.size()) cou.resize(v+1, 0);
			++cou[v];
		}
		void dec(int v) {
			if (v >= 0) --cou[v];
			if (v > 0) ++cou[v-1];
			if (!cou.empty() && cou.back() == 0) cou.pop_back();
		}
		int max() const {
			return (int)cou.size() - 1;
		}
};

const int N = 5 * (int)1e5;
vector<int> conns[N]; // Edges from node i

int par[N]; // parent of node i
int dp[N]; // If we root the tree at i, number of subtrees with depth at least current depth
bool odd_add[N]; // Whether dp[i] got decremented in the previous step

DecMax act[N]; // values of dp for children of this node
DecMax even_cou; // values of type dp[a] + dp[b] - 2 for adjacent a, b. For every a, only store pair with the child b that maximizes the value.
DecMax odd_cou; // values of type dp[i] + odd_add[i]
DecMax both_cou; // values of dp[i]

// Calculate parents
void dfs(int i, int p) {
	par[i] = p;
	for (auto t : conns[i]) {
		if (t != p) dfs(t, i);
	}
}

// Calculate offer from node i to even_cou
int off(int i) {
	return dp[i] + act[i].max() - 2;
}

// Update odd_add, odd_que and odd_cou when dp[i] decreases by one
void oddFlag(int i, vector<int>& odd_que) {
	if (! odd_add[i]) {
		odd_add[i] = true;
		odd_que.push_back(i);
	} else {
		odd_cou.dec(dp[i]+1);
	}
}

// Update values when dp[i] decreases by one
void decDP(int i, vector<int>& nxt_que, vector<int>& odd_que) {
	// Update even_cou and act
	if (par[i] != -1) {
		int p = par[i];
		int v = dp[p] + act[p].max() - 2;
		act[p].dec(dp[i]);
		if (off(p) < v) even_cou.dec(v);
	}

	int v = dp[i] + act[i].max() - 2;
	even_cou.dec(v);

	oddFlag(i, odd_que);
	both_cou.dec(dp[i]);

	dp[i] -= 1;
	if (dp[i] == 1) {
		for (auto t : conns[i]) nxt_que.push_back(t);
	}
}

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
	dfs(0, -1);


	// Init all values
	vector<int> dp_que, odd_que;
	for (int i = 0; i < n; ++i) {
		dp[i] = conns[i].size();
		if (par[i] != -1) {
			act[par[i]].init(dp[i]);
		}
		both_cou.init(dp[i]);

		odd_cou.init(dp[i] + 1);
		oddFlag(i, odd_que);

		if (dp[i] == 1) {
			for (auto t : conns[i]) dp_que.push_back(t);
		}
	}
	for (int i = 0; i < n; ++i) {
		even_cou.init(dp[i] + act[i].max() - 2);
	}

	// Loop current k. At the beginning of each step, dp[i] will be the number of subtrees with depth at least k, if we rooted the tree at i.
	// Then answer for 2k is maximum of dp[a] + dp[b] - 2 (-2 to not count eachother) and dp[i] over all adjacent (a, b) and i,
	// and answer for 2k-1 is maximum of dp[i] + (some subtree has depth exactly i-1) = dp[i] + odd_add[i] over all i.

	vector<int> ans(n, 1);
	for (int k = 1; 2*k-1 <= n; ++k) {
		int off1 = max(1, both_cou.max());
		int off2 = even_cou.max();
		int off3 = odd_cou.max();
		if (2*k <= n) ans[2*k-1] = max(off1, off2);
		if (2*k-1 <= n) ans[2*k-2] = max(off1, off3);

		// Update dp-values
		// dp'[i] = \sum_{t \in conns[i]} max(1, dp[t]) - 1
		// hence we can store in a queue which dp-values we much decrement. When a dp-value goes to <= 1, push its neighbours to the queue.
		for (auto i : odd_que) {
			odd_add[i] = false;
			odd_cou.dec(dp[i]+1);
		}
		odd_que.clear();

		vector<int> nxt_que;
		for (auto i : dp_que) decDP(i, nxt_que, odd_que);
		dp_que = nxt_que;
	}

	for (auto v : ans) cout << v << ' '; cout << '\n';
}