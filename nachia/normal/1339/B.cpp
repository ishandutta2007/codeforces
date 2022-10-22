#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

template<class Ty>
using passive_queue = priority_queue<Ty, vector<Ty>, greater<Ty>>;

struct Problem {

	void Loop() {
		UL N; cin >> N;
		vector<int> A(N); rep(i, N) cin >> A[i];
		sort(A.begin(), A.end());
		int p = 0, q = N - 1;
		vector<int> ans;
		while (p <= q) {
			ans.push_back(A[p]);
			if (p < q) ans.push_back(A[q]);
			p++; q--;
		}
		reverse(ans.begin(), ans.end());
		rep(i, N) {
			if (i) cout << " ";
			cout << ans[i];
		} cout << endl;
	}

	void Solve() {
		UL Q; cin >> Q;
		rep(i, Q) {
			Loop();
		}
	}

	Problem();
};
int main() {
	unique_ptr<Problem> p(new Problem());
	p->Solve();
	return 0;
}
Problem::Problem() {
	cout << fixed << setprecision(10);
}