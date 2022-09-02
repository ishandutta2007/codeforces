#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1 << 20;
const int M = 5 * (int)1e5;
vector<int> conns[N];
int edge_ind[N];
bool used[M];
int as[M];
int bs[M];

void eulerTour(int i, vector<int>& path) {
	while(edge_ind[i] < conns[i].size()) {
		int ind = conns[i][edge_ind[i]];
		if (used[ind]) ++edge_ind[i];
		else {
			used[ind] = 1;
			if (as[ind] == i) {
				eulerTour(bs[ind], path);
				path.push_back(2*ind + 2);
				path.push_back(2*ind + 1);
			} else {
				eulerTour(as[ind], path);
				path.push_back(2*ind + 1);
				path.push_back(2*ind + 2);
			}
		}
	}
}

vector<int> findPath(int h, const vector<int>& vals) {
	// Build graph
	int n = vals.size() / 2;
	int mask = (1 << h) - 1;
	for (int i = 0; i < n; ++i) {
		used[i] = 0;
		as[i] = vals[2*i] & mask;
		bs[i] = vals[2*i+1] & mask;
		conns[as[i]].push_back(i);
		conns[bs[i]].push_back(i);
	}

	// Build neclace
	bool fail = 0;
	for (int i = 0; i <= mask; ++i) {
		if (conns[i].size() & 1) fail = 1; // no tour if odd-degree vertex
	}
	vector<int> path;
	if (! fail) {
		eulerTour(as[0], path);
		if (path.size() < 2*n) fail = 1;
	}

	// Clean up
	for (int i = 0; i <= mask; ++i) {
		conns[i].clear();
		edge_ind[i] = 0;
	}

	// Answer
	if (fail) return {};
	else return path;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	// Binary search answer
	// Or linear search, I don't care
	
	// Just cut the high bits off. The low bits must be equal
	// Possible IFF every group of equal values has an even number of entries, and the graph is connected
	// In this case, just take a euler tour

	vector<int> vals(2*n);
	for (int& v : vals) cin >> v;

	int low = 0;
	int high = 20;
	while(low != high) {
		int h = (low + high + 1) >> 1;
		if (findPath(h, vals).empty()) high = h - 1;
		else low = h;
	}

	cout << low << '\n';
	auto path = findPath(low, vals);
	for (auto i : path) cout << i << ' '; cout << '\n';
}