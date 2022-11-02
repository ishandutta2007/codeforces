#include <bits/stdc++.h>
using namespace std;

using lld = long long;

bool check(vector<lld> A, int lb)
{
	int N = A.size()-1;
	vector<lld> B(N+1), d(N+1);
	for (int i=N;i;i--){
		if (A[i]+B[i] < lb) return 0;
		d[i] = (A[i]+B[i]-lb)/3;
		if (d[i]*3 > A[i]) d[i] = A[i]/3;
		if (i >= 3) B[i-1] += d[i], B[i-2] += 2*d[i];
	}
	return 1;
}

void solve()
{
	int N;
	cin >> N;
	vector<lld> A(N+1);
	for (int i=1;i<=N;i++) cin >> A[i];
	int s = 1, e = 1e9, ans = 0;
	while (s <= e){
		int m = s+e >> 1;
		if (check(A, m)) s = m+1, ans = m;
		else e = m-1;
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