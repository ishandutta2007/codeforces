#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int K = 60;
const int N = 2 * (int)1e5;
int fib[K];
set<int> g[N];

int findCentroid(int i, int p, int n) {
	int res = 1;
	for (auto t : g[i]) {
		if (t == p) continue;
		int sub = findCentroid(t, i, n);
		if (sub <= 0) return sub;
		else res += sub;
	}
	if (2*res >= n) return -i;
	else return res;
}

pair<int, int> findComp(int i, int p, int k) {
	pair<int, int> res = {-1, 1};
	for (auto t : g[i]) {
		if (t == p) continue;
		auto sub = findComp(t, i, k);
		if (sub.first != -1) return sub;
		else res.second += sub.second;
	}
	if (res.second == fib[k]) return {i, p};
	else return res;
}

bool solve(int i, int k) {
	while(true) {
		if (k <= 3) return true;
		i = -findCentroid(i, -1, fib[k]);

		pair<int, int> cut = findComp(i, -1, k-2);
		if (cut.first == -1) return false;

		g[cut.second].erase(cut.first);
		g[cut.first].erase(cut.second);
		
		if (! solve(cut.first, k-2)) return false;
		--k;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	fib[0] = 1;
	fib[1] = 1;
	int k = 1;
	while(fib[k] < n) {
		++k;
		fib[k] = fib[k-1] + fib[k-2];
	}

	// Start at centroid
	// Find candidates for F_{k-2}
	//	if there are two, we actually have to use both of them!
	
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].insert(b);
		g[b].insert(a);
	}

	if (fib[k] != n) {
		cout << "NO\n";
	} else {
		bool res = solve(0, k);
		if (res) cout << "YES\n";
		else cout << "NO\n";
	}
}