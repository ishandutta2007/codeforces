#include <bits/stdc++.h>
using namespace std;

using lld = long long;

const int MOD = 998244353;

int choose(int n, int m)
{
	static int i = 1;
	static int C[5001][5001] = {0,};
	C[0][0] = 1;
	for (;i<=n;i++){
		for (int j=0;j<=i;j++) C[i][j] = (C[i-1][j] + (j > 0 ? C[i-1][j-1] : 0))%MOD;
	}
	return C[n][m];
}

void solve()
{
	int N, K;
	cin >> N >> K;
	vector<bool> A(N+1);
	{
		string s; cin >> s;
		for (int i=1;i<=N;i++) A[i] = s[i-1] == '1';
	}

	int cnt = 0;
	for (int i=1;i<=N;i++) if (A[i]) cnt++;
	if (cnt < K){ cout << "1\n"; return; }

	int ans = 1;
	for (int i=1;i<=N;i++){
		int cnt = 0;
		for (int j=i;j<=N;j++){
			if (A[j]) cnt++;
			if (cnt > K) break;
			int one = cnt, zero = j-i+1-cnt;
			if (A[i]) zero--;
			else one--;
			if (A[j]) zero--;
			else one--;
			if (one < 0 || zero < 0) continue;
			ans = (ans+choose(zero+one, zero))%MOD;
		}
	}
	cout << ans << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
}