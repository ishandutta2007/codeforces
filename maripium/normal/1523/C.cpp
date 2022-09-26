#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A;
		for (int i = 0; i < N; ++i) {
			int v; cin >> v;
			if (v == 1) {
				A.push_back(v);
			} else {
				while (A.back() != v - 1) A.pop_back();
				A.back() ++;
			}
			bool f = true;
			for (int v : A) {
				if (!f) cout << '.';
				cout << v;
				f = false;
			}
			cout << '\n';
		}
	}	
}