#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int N = 1000;
vector<int> conns[N];
bool mark[N];

int dfs(int i, int p) {
	if (mark[i]) return i;
	for (auto t : conns[i]) {
		if (t == p) continue;
		int sub = dfs(t, i);
		if (sub != -1) return sub;
	}
	return -1;
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
	}

	int k1;
	cin >> k1;
	for (int i = 0; i < k1; ++i) {
		int j;
		cin >> j;
		mark[j-1] = true;
	}

	int k2;
	cin >> k2;
	vector<int> bs(k2);
	for (int i = 0; i < k2; ++i) cin >> bs[i];

	// Ask for label of some node in li chen's tree.
	// Then, find the closest node in your tree.
	// Ask for label of that one. It is the only one that can be a intersection
	cout << "B " << bs[0] << endl;
	int s;
	cin >> s;
	--s;
	int t = dfs(s, s);
	cout << "A " << (t+1) << endl;
	int j;
	cin >> j;

	bool fail = true;
	for (auto v : bs) {
		if (v == j) {
			fail = false;
			cout << "C " << t+1 << endl;
			break;
		}
	}
	if (fail) {
		cout << "C -1" << endl;
	}

	// Reset tree
	for (int i = 0; i < n; ++i) {
		conns[i].clear();
		conns[i].shrink_to_fit();
		mark[i] = false;
	}
}

int main() {
	int t;
	cin >> t;
	for (int q = 0; q < t; ++q) solve();
}