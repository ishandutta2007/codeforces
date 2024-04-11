#include <bits/stdc++.h>
using namespace std;

using lld = long long;

void solve()
{
	int N; lld K;
	cin >> N >> K;
	vector<int> A(N+1);
	for (int i=1;i<=N;i++) cin >> A[i];
	sort(A.begin()+1, A.end());

	lld sum = 0;
	for (int i=1;i<=N;i++) sum += A[i];

	lld ans = max(0LL, sum-K);
	sum -= A[1];
	for (int i=N;i>1;i--){
		int c = N-i+2;
		sum -= A[i];
		// sum + c*x <= K
		// x <= (K-sum) / c
		lld x = K >= sum ? (K-sum)/c : -((sum-K-1)/c+1);
		ans = min(ans, max(0LL, A[1]-x)+N-i+1);
	}
	cout << ans << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	for (cin >> T;T--;) solve();
}