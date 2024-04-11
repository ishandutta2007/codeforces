#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		multiset<int64_t> A;
		int64_t sum = 0;
		for (int i = 0; i < N; ++i) {
			int64_t a; cin >> a;
			sum += a;
			A.insert(a);
		}	

		multiset<int64_t> B; B.insert(sum);
		bool fail = false;
		while (A.size()) {
			while (A.size() && *prev(A.end()) == *prev(B.end())) {
				A.erase(prev(A.end()));
				B.erase(prev(B.end()));
				// cerr << "ERASE\n";
			}
			if (A.empty()) break;
			if (*prev(A.end()) > *prev(B.end())) {
				fail = true;
				break;
			}
			int64_t v = *prev(B.end());
			B.erase(prev(B.end()));
			B.insert(v / 2);
			B.insert((v + 1) / 2);
		}
		cout << (fail ? "NO" : "YES") << '\n';
	}
}