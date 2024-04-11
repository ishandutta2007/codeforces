#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 5 * (int)1e5;
vector<int> conns[N];
int tar[N];
int cur[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
	}

	// We can always add in order of target topic
	vector<int> que;
	for (int i = 0; i < n; ++i) {
		cur[i] = 1;
		cin >> tar[i];
		if (cur[i] == tar[i]) que.push_back(i);
	}

	bool fail = 0;
	for (int j = 0; j < que.size(); ++j) {
		int i = que[j];
		if (cur[i] != tar[i]) fail = 1; // caused by two equal adjacent target labels
		for (auto t : conns[i]) {
			if (cur[t] == tar[i]) {
				++cur[t];
				if (cur[t] == tar[t]) que.push_back(t);
			}
		}
	}
	fail |= (que.size() < n);

	if (fail) cout << -1 << '\n';
	else {
		for (auto i : que) cout << i+1 << ' '; cout << '\n';
	}
}