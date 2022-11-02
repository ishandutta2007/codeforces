#include <bits/stdc++.h>
using namespace std;

using lld = long long;

void solve()
{
	int N;
	cin >> N;
	int C[N+N+1][N+N+1];
	for (int i=1;i<=N+N;i++) for (int j=1;j<=N+N;j++) cin >> C[i][j];

	lld ans_base = 0;
	for (int i=1;i<=N;i++) for (int j=1;j<=N;j++) ans_base += C[N+i][N+j];

	int mn = min({
		C[1][N+N], C[N+N][1],
		C[1][N+1], C[N+N][N],
		C[N][N+N], C[N+1][1],
		C[N+1][N], C[N][N+1],
	});
	cout << ans_base + mn << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	for (cin >> T;T--;) solve();
}