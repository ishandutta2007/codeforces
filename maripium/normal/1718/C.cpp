#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	vector<int64_t> fibs;
	fibs.push_back(1);
	fibs.push_back(1);
	for (int i = 2; i < 60; ++i) {
		fibs.push_back(fibs[i - 1] + fibs[i - 2]);
	}
	int T; cin >> T;
	while (T--) {
		int N, Q; cin >> N >> Q;
		vector<int> A(N); for (int &a : A) cin >> a;
		int N0 = N;
		vector<int> prs;
		for (int i = 2; i <= N; ++i) if (N0 % i == 0) {
			prs.push_back(i);
			while (N0 % i == 0) N0 /= i;
		}
		int P = int(prs.size());
		vector<vector<int64_t>> vals(P);
		for (int j = 0; j < P; ++j) {
			vals[j].resize(N / prs[j]);
			for (int i = 0; i < N; ++i) vals[j][i % (N / prs[j])] += int64_t(N / prs[j]) * A[i];
		}
		multiset<int64_t> st;
		for (int j = 0; j < P; ++j) {
			for (int i = 0; i < N / prs[j]; ++i) st.insert(vals[j][i]);
		}
		cout << (*st.rbegin()) << '\n';
		while (Q--) {
			int i, x; cin >> i >> x; --i, x -= A[i];
			A[i] += x;
			for (int j = 0; j < P; ++j) {
				st.erase(st.find(vals[j][i % (N / prs[j])]));
				vals[j][i % (N / prs[j])] += int64_t(x) * (N / prs[j]);
				st.insert(vals[j][i % (N / prs[j])]);
			}
			cout << (*st.rbegin()) << '\n';
		}
	}
	return 0;
}