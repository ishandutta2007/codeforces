#include <bits/stdc++.h>

using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N, M, P; cin >> N >> M >> P;
	vector<uint64_t> A(N);
	for (int i = 0; i < N; ++i) {
		string str; cin >> str;
		for (int j = 0; j < M; ++j) A[i] |= uint64_t(str[j] - '0') << j;
	}
	
	int ans = 0;
	uint64_t mask = 0;
	for (int it = 0; it < 60; ++it) {
		int r = rng() % N;
		vector<int> bits;
		for (int j = 0; j < M; ++j) if (A[r] >> j & 1) bits.push_back(j);
		int B = int(bits.size());
		vector<int> C(1 << B);
		for (int i = 0; i < N; ++i) {
			int m = 0;
			for (int j = 0; j < B; ++j) {
				if (A[i] >> (bits[j]) & 1) m |= (1 << j);
			}
			C[m] ++;
		}
		for (int i = 0; i < B; ++i) {
			for (int j = 0; j < (1 << B); ++j) if (j >> i & 1) {
				C[j ^ (1 << i)] += C[j];
			}
		}
		int cans = 0;
		int cmask = 0;
		for (int i = 0; i < (1 << B); ++i) {
			if (C[i] >= (N + 1) / 2) {
				int c = __builtin_popcount(i);
				if (cans < c) {
					cans = c;
					cmask = i;
				}
			}
		}
		uint64_t cmask2 = 0;
		for (int j = 0; j < B; ++j) if (cmask >> j & 1) cmask2 |= (uint64_t(1) << bits[j]);
		if (cans > ans) {
			ans = cans;
			mask = cmask2;
		} 
	}
	for (int i = 0; i < M; ++i) {
		cout << (mask >> i & 1);
	}
	return 0;
}