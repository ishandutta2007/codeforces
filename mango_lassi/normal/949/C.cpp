#include <iostream>
#include <vector>
#include <utility>
using namespace std;

const long long inf = 1e18;
const long long N = 202020;
vector<long long> conns[N];
vector<long long> ins[N];
vector<pair<int, int>> clients;
long long upd[N];
long long group[N];
long long gsize[N];
bool hasouts[N];
vector<long long> order;

void dfs(long long i) {
	if (group[i] != 0) return;
	group[i] = -1;
	for (auto t : conns[i]) dfs(t);
	order.push_back(i);
}
void dfs2(long long i, long long g) {
	if (group[i] != -1) return;
	group[i] = g;
	++gsize[g];
	for (auto t : ins[i]) dfs2(t, g);
}

int main() {
	long long n, m, h;
	cin >> n >> m >> h;
	for (long long i = 0; i < n; ++i) {
		cin >> upd[i];
	}
	for (long long i = 0; i < m; ++i) {
		long long a, b;
		cin >> a >> b;
		--a; --b;
		clients.push_back({a, b});
		if (((upd[a] + 1) % h) == upd[b]) {
			conns[a].push_back(b);
			ins[b].push_back(a);
		}
		if (((upd[b] + 1) % h) == upd[a]) {
			conns[b].push_back(a);
			ins[a].push_back(b);
		}
	}
	for (long long i = 0; i < n; ++i) dfs(i);

	long long gc = 0;
	for (long long j = n-1; j >= 0; --j) {
		long long i = order[j];
		if (group[i] == -1) {
			dfs2(i, gc);
			++gc;
		}
	}

	for (long long i = 0; i < n; ++i) {
		for (auto t : conns[i]) {
			if (group[t] != group[i]) hasouts[group[i]] = true;
		}
	}
	
	// for (long long i = 0; i < n; ++i) cout << group[i] << ' '; cout << '\n';
	// for (long long i = 0; i < gc; ++i) cout << gsize[i] << ' '; cout << '\n';
	// for (long long i = 0; i < gc; ++i) cout << hasouts[i] << ' '; cout << '\n';

	long long gs = inf;
	long long gi = -1;
	for (long long i = 0; i < gc; ++i) {
		if (hasouts[i]) continue;
		if ((gsize[i] > 0) && (gsize[i] < gs)) {
			gs = gsize[i];
			gi = i;
		}
	}

	/*
	for (long long i = 0; i < n; ++i) {
		if (group[i] != gi) continue; 
		for (auto t : conns[i]) {
			if (group[t] != gi) {
				cout << "BUG FOUND!\n";
				return 1;
			}
		}
	}
	*/

	cout << gsize[gi] << '\n';
	for (long long i = 0; i < n; ++i) {
		if (group[i] == gi) cout << i+1 << ' ';
	}
	cout << '\n';
	/*
	for (auto it : clients) {
		if (upd[it.first] == upd[it.second]) {
			cout << "BUG FOUND!\n";
			break;
		}
	}
	*/

}