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

	void Solve() {
		UL N; cin >> N;
		vector<ULL> A(100000);
		rep(i, N) {
			UL a; cin >> a; A[a - 1] += a;
		}
		vector<ULL> dp(100002);
		rep(i, 100000) {
			dp[i + 2] = max(dp[i + 2], dp[i] + A[i]);
			dp[i + 1] = max(dp[i], dp[i + 1]);
		}
		reverse(dp.begin(), dp.end());
		cout << (max(dp[0], dp[1])) << endl;
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