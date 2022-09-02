#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5;
int cou[N];
vector<int> conns[N];

void dfs(int i, int p, int d) {
	++cou[d];
	for (auto t : conns[i]) {
		if (t == p) continue;
		dfs(t, i, d+1);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int p;
		cin >> p;
		--p;
		conns[i].push_back(p);
		conns[p].push_back(i);
	}
	dfs(0, 0, 0);
	int res = 0;
	for (int i = 0; i < n; ++i) {
		if (cou[i] & 1) ++res;
	}
	cout << res << '\n';
}