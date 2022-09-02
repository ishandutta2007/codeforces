#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int INF = (int)1e9 + 7;

const int K = 20;
int state[2][1<<K];

int apply(const string& str, const vector<int>& perm, int dir) {
	int res = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (dir == 1) {
			res |= (str[i] == '1' ? 1 : 0) << perm[i];
		} else {
			res |= (str[perm[i]] == '1' ? 1 : 0) << i;
		}
	}
	return res;
}
void clear(int d, int k) {
	for (int j = 0; j < (1 << k); ++j) state[d][j] = INF;
}
void applyMin(int& a, int b) {
	a = min(a, b);
}

void stringPrint(int i, int k) {
	for (int j = 0; j < k; ++j) {
		if (i & (1 << j)) cout << '1';
		else cout << '0';
	}
	cout << ' ';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	string str, tar;
	cin >> str >> tar;

	vector<pair<int, int>> swaps(n);
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		swaps[i] = {a, b};
	}

	// Trivial DP is 2^k * n:
	//	For every position r, given where there currently are 0's and 1's, you store minimum l such that the swaps {l, ..., r} achieve that position.

	// We can store the permutation that the sequence of elves starting from that point make
	// At every position, store what tray we get if we apply that to our initial tray, and what tray we get if we apply its inverse to our target tray
	// Answer is the minimum amount of differring positions between permuted_ini_tray[i] and permuted_tar_tray[j] for |i-j| >= m.

	// This can in turn be found with simultaneous BFS. At step t, store for every position x in the 2^k unit cube the minimum i and maximum i such that
	// |permuted_ini_tray[i] - x| <= t. Answer is the minimum t for which the minimum i or maximum i at permuted_tar_tray[j] has |i - j| >= m.

	vector<int> as(n+1), bs(n+1);

	vector<int> perm(k);
	for (int i = 0; i < k; ++i) perm[i] = i;

	as[n] = apply(str, perm, 1);
	bs[n] = apply(tar, perm, 1);
	
	for (int i = n-1; i >= 0; --i) {
		swap(perm[swaps[i].first], perm[swaps[i].second]);
		as[i] = apply(str, perm, 1);
		bs[i] = apply(tar, perm, 1);
	}

	/*
	for (int i = 0; i <= n; ++i) stringPrint(as[i], k);
	cout << '\n';
	for (int i = 0; i <= n; ++i) stringPrint(bs[i], k);
	cout << '\n';
	*/

	clear(0, k);
	clear(1, k);
	for (int i = 0; i <= n; ++i) applyMin(state[0][as[i]], i);

	bool found = 0;
	for (int t = 0; t <= k; ++t) {
		for (int j = 0; j <= n; ++j) {
			int i = state[0][bs[j]];
			if (i + m <= j) {
				cout << k - t << '\n';
				cout << i+1 << ' ' << j << '\n';
				found = 1;
				break;
			}
		}
		if (found) break;
		
		for (int j = 0; j < (1 << k); ++j) {
			for (int i = 0; i < k; ++i) {
				applyMin(state[1][j], state[0][j ^ (1 << i)]);
			}
		}
		for (int j = 0; j < (1 << k); ++j) state[0][j] = state[1][j];
		clear(1, k);
	}
}