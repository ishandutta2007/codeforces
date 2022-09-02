#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
const int N = 1e5;
const int M = 64;
vector<int> apps[M];
vector<int> conns[N];
vector<pair<int, int>> ed;
int vis[N];
int dist[N];

void handle(int j, int bi, vector<int>& bfs) {
	int i = bfs[j];
	for (auto ei : conns[i]) {
		if (ei == bi) continue;
		int t = (ed[ei].first == i ? ed[ei].second : ed[ei].first);
		if (vis[t] < bi + 1) {
			vis[t] = bi + 1;
			dist[t] = dist[i] + 1;
			bfs.push_back(t);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		ll v;
		cin >> v;
		for (int j = 0; (1ll << j) <= v; ++j) {
			if (v & (1ll << j)) {
				apps[j].push_back(i);
			}
		}
	}
	int res = INF;
	for (int i = 0; i < M; ++i) {
		if (apps[i].size() >= 3) res = 3;
		else if (apps[i].size() == 2) {
			int a = apps[i][0];
			int b = apps[i][1];
			int ei = ed.size();
			if (b < a) swap(a, b);
			ed.emplace_back(a, b);
		}
	}
	if (res >= INF) {
		sort(ed.begin(), ed.end());
		ed.erase(unique(ed.begin(), ed.end()), ed.end());
		for (int ei = 0; ei < ed.size(); ++ei) {
			int a = ed[ei].first;
			int b = ed[ei].second;
			conns[a].push_back(ei);
			conns[b].push_back(ei);
		}
		for (int bi = 0; bi < ed.size(); ++bi) {
			vector<int> bfs;
			int src = ed[bi].first;
			int tar = ed[bi].second;

			vis[src] = bi + 1;
			dist[src] = 0;
			bfs.push_back(src);
			for (int j = 0; j < bfs.size(); ++j) handle(j, bi, bfs);
			if (vis[tar] == bi + 1) {
				res = min(res, dist[tar] + 1);
			}
		}
	}
	if (res < INF) cout << res << '\n';
	else cout << -1 << '\n';
}