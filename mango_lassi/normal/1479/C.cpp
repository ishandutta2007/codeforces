#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 31;

vector<pair<pair<int, int>, int>> build(int a, int b) {
	vector<pair<pair<int, int>, int>> res;
	if (b == 1) {
		res.emplace_back(make_pair(1, N), 1);
	} else if (b == 2) {
		res.emplace_back(make_pair(1, N), 1);
		res.emplace_back(make_pair(1, N-1), 1);
		res.emplace_back(make_pair(N-1, N), 1);
	} else if (b == 3) {
		res.emplace_back(make_pair(1, N), 1);
		res.emplace_back(make_pair(1, N-1), 1);
		res.emplace_back(make_pair(1, N-2), 1);
		res.emplace_back(make_pair(N-1, N), 1);
		res.emplace_back(make_pair(N-2, N-1), 1);
	} else {
		res.emplace_back(make_pair(1, N), 1);

		for (int i = N-1; i > 1; --i) {
			int bit = 1 << (N-1 - i);
			if (bit > b) {
				break;
			} else if (2*bit > b) {
				// Highest bit!
				if (bit > 2) res.emplace_back(make_pair(1, i), bit - 2);

				int cur = 1;
				for (int j = i+1; j < N; ++j) {
					int off = 1 << (N-1-j);
					if (b & off) {
						res.emplace_back(make_pair(i, j), cur);
						cur += off;
					}
				}
				res.emplace_back(make_pair(i, N), cur + 1);
			} else {
				if (bit > 1) res.emplace_back(make_pair(1, i), bit - 1);
				for (int j = i+1; j < N; ++j) {
					res.emplace_back(make_pair(i, j), (1 << (N-1-j)));
				}
				res.emplace_back(make_pair(i, N), 1);
			}
		}
	}
	return res;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// YES
	// L > 1: build paths to city 31, connect 31 to 32 with a path of length L - 1
	// 

	int a, b;
	cin >> a >> b;

	cout << "YES\n";

	if (a == 1) {
		vector<pair<pair<int, int>, int>> edges = build(1, b);
		cout << N << ' ' << edges.size() << '\n';
		for (auto pr : edges) cout << pr.first.first << ' ' << pr.first.second << ' ' << pr.second << '\n';
	} else {
		vector<pair<pair<int, int>, int>> edges = build(1, b-a+1);
		cout << N+1 << ' ' << edges.size()+1 << '\n';
		for (auto pr : edges) cout << pr.first.first << ' ' << pr.first.second << ' ' << pr.second << '\n';
		cout << N << ' ' << N+1 << ' ' << a-1 << '\n';
	}
}