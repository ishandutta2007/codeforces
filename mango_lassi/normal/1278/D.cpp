#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
using ll = long long;

const int N = 5 * (int)1e5;
vector<int> conns[N];
int ev[2*N];
int itv[N];
bool vis[N];

int count(int i) {
	if (vis[i]) return 0;
	vis[i] = true;
	int res = 1;
	for (auto t : conns[i]) res += count(t);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		ev[a-1] = i+1;
		ev[b-1] = -(i+1);
		itv[i] = b-1;
	}

	// Just construct: not tree if n or more edges
	// How to construct? segment a intersects with all s.t. start[b] < end[a] < end[b]
	// Maintain set of all active endpoints

	int m = 0;
	set<int> act;
	for (int i = 0; i < 2*n && m < n; ++i) {
		if (ev[i] > 0) {
			int j = ev[i] - 1;
			auto it = act.begin();
			while((it != act.end()) && (*it < itv[j]) && (m < n)) {
				int t = -ev[*it] - 1;
				conns[j].push_back(t);
				conns[t].push_back(j);
				++m;
				++it;
			}
			act.insert(itv[j]);
		} else {
			act.erase(i);
		}
	}

	if (m == n-1 && count(0) == n) cout << "YES\n";
	else cout << "NO\n";
}