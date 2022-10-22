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
		vector<pair<UL, UL>> A(N);
		rep(i, N) cin >> A[i].first >> A[i].second;
		sort(A.begin(), A.end());
		vector<UL> dp(N);
		dp[0] = 1;
		for (UL i = 1; i < N; i++) {
			if (A[i - 1].second <= A[i].second)
				dp[i] |= dp[i - 1];
			if (A[i - 1].first <= A[i].second)
				dp[i] |= 1;
		}
		UL ans = A[N - 1].first;
		if (dp[N - 1]) ans = min(ans, A[N - 1].second);
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