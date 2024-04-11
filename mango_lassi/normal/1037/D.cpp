#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

const int N = 2 * (int)1e5;
vector<pair<int, int>> conns[N];
int ord[N];
bool visit[N];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back({-1, b});
		conns[b].push_back({-1, a});
	}

	for (int i = 0; i < n; ++i) {
		int s;
		cin >> s;
		ord[s-1] = i;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < conns[i].size(); ++j) {
			conns[i][j].first = ord[conns[i][j].second];
		}
		sort(conns[i].begin(), conns[i].end());
	}
	
	vector<int> que = {0};
	visit[0] = true;

	for (int j = 0; j < que.size(); ++j) {
		int i = que[j];
		for (auto ed : conns[i]) {
			int t = ed.second;

			if (! visit[t]) {
				visit[t] = true;
				que.push_back(t);
			}
		}
	}
	
	bool fail = false;
	if (que.size() != n) {
		fail = true;
	} else {
		for (int i = 0; i < n; ++i) {
			if (ord[que[i]] != i) fail = true;
		}
	}
	if (fail) {
		cout << "No\n";
	} else {
		cout << "Yes\n";
	}
}