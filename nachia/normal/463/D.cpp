#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)



struct Problem {

	struct V {
		UL F[5] = {};
		bool operator<(const V &r) const {
			rep(i, 5) {
				if (F[i] < r.F[i]) return true;
				if (F[i] > r.F[i]) return false;
			}
			return false;
		}
		bool strict(const V &r) const {
			rep(i, 5) if (F[i] > r.F[i]) return false;
			return true;
		}
	};

	void Solve() {
		UL N, K; cin >> N >> K;
		vector<V> A(N);
		rep(k, K) {
			rep(i, N) {
				UL v; cin >> v; v--;
				A[v].F[k] = i;
			}
		}
		sort(A.begin(), A.end());
		vector<UL> dp(N);
		UL ans = 0;
		rep(i, N) {
			UL p = 0;
			rep(j, i) {
				if (A[j].strict(A[i])) p = max(p, dp[j]);
			}
			dp[i] = p + 1;
			ans = max(ans, dp[i]);
		}
		cout << ans << endl;
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