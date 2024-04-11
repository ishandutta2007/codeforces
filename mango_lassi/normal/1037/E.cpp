#include <iostream>
#include <vector>
using namespace std;

const int N = 2 * (int)1e5;
const int M = 2 * (int)1e5;
vector<int> conns[N];
int cou[N];
bool is_act[N];
int actives;

int edge_a[M];
int edge_b[M];
int ans[M];

int k;

void disable(int i) {
	if (! is_act[i]) return;
	is_act[i] = false;
	--actives;

	for (auto t : conns[i]) {
		--cou[t];
		if (cou[t] < k) disable(t);
	}
}

int main() {
	int n, m;
	cin >> n >> m >> k;
	
	// Initially all nodes are enabled.
	// Then take all nodes that are enabled but have less than k friends and disable them.
	// Repeat this, until nothing changes.
	// A O(n + m) algorithm.

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		edge_a[i] = a;
		edge_b[i] = b;

		conns[a].push_back(b);
		conns[b].push_back(a);
		++cou[a];
		++cou[b];
	}
	
	actives = n;
	for (int i = 0; i < n; ++i) is_act[i] = true;

	for (int i = 0; i < n; ++i) {
		if (cou[i] < k) disable(i);
	}
	
	ans[m-1] = actives;
	for (int i = m-1; i > 0; --i) {
		int a = edge_a[i];
		int b = edge_b[i];
		if (is_act[a]) --cou[b];
		if (is_act[b]) --cou[a];
		conns[a].pop_back();
		conns[b].pop_back();

		if (cou[a] < k) disable(a);
		if (cou[b] < k) disable(b);

		ans[i-1] = actives;
	}

	for (int i = 0; i < m; ++i) cout << ans[i] << ' '; cout << '\n';
}