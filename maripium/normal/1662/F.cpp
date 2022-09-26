#include <bits/stdc++.h>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, A, B; cin >> N >> A >> B; --A, --B;
		vector<int> P(N); for (int &a : P) cin >> a;
		
		int S = 1;
		while (S < N) S *= 2;
		vector<priority_queue<pair<int, int>>> st0(S * 2);
		vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> st1(S * 2);

		for (int i = 0; i < N; ++i) {
			for (int v = i + S; v > 0; v /= 2) {
				st0[v].push(make_pair(i + P[i], i));
				st1[v].push(make_pair(i - P[i], i));
			}
		}

		vector<int> dist(N, -1);
		dist[A] = 0;
		queue<int> bfs;
		bfs.push(A);
		while (bfs.size()) {
			int v = bfs.front(); bfs.pop();

			for (int l = max(v - P[v], 0) + S, r = v + S; l <= r; l /= 2, r /= 2) {
				if (l % 2) {
					while (st0[l].size() && st0[l].top().first >= v) {
						int u = st0[l].top().second;
						st0[l].pop();
						if (dist[u] == -1) {
							dist[u] = dist[v] + 1;
							bfs.push(u);
						}
					}
					l++;
				}
				if (r % 2 == 0) {
					while (st0[r].size() && st0[r].top().first >= v) {
						int u = st0[r].top().second;
						st0[r].pop();
						if (dist[u] == -1) {
							dist[u] = dist[v] + 1;
							bfs.push(u);
						}
					}
					r--;
				}
			}

			for (int l = v + S, r = min(v + P[v], N - 1) + S; l <= r; l /= 2, r /= 2) {
				if (l % 2) {
					while (st1[l].size() && st1[l].top().first <= v) {
						int u = st1[l].top().second; st1[l].pop();
						if (dist[u] == -1) {
							dist[u] = dist[v] + 1;
							bfs.push(u);
						}
					}
					l++;
				}
				if (r % 2 == 0) {
					while (st1[r].size() && st1[r].top().first <= v) {
						int u = st1[r].top().second; st1[r].pop();
						if (dist[u] == -1) {
							dist[u] = dist[v] + 1;
							bfs.push(u);
						}
					}
					r--;
				}
			}
		}
		cout << dist[B] << '\n';
	}
	return 0;
}