#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int INF = (int)1e9 + 7;
const int N = 2 * (int)1e5;
vector<int> conns[N];
vector<int> pre[N];
int dist[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int j = 0; j < m; ++j) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[b].push_back(a);
	}

	int k;
	cin >> k;
	vector<int> path(k);
	for (int& i : path) {
		cin >> i;
		--i;
	}

	int tar = path[k-1];
	for (int i = 0; i < n; ++i) {
		dist[i] = INF;
	}
	dist[tar] = 0;
	vector<int> que = {tar};
	for (int j = 0; j < que.size(); ++j) {
		int i = que[j];
		for (auto t : conns[i]) {
			if (dist[t] > dist[i] + 1) {
				dist[t] = dist[i] + 1;
				que.push_back(t);
			}
			if (dist[t] >= dist[i] + 1) {
				pre[t].push_back(i);
			}
		}
	}

	int low = 0;
	int high = 0;
	for (int j = 0; j+1 < k; ++j) {
		int i = path[j];
		int t = path[j+1];

		int act = 0, oth = 0;
		for (auto ed : pre[i]) {
			if (ed == t) ++act;
			else ++oth;
		}
		if (act == 0) ++low;
		if (oth > 0) ++high;
	}
	cout << low << ' ' << high << '\n';
}