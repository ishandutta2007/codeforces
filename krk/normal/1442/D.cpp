#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 3005;

int n, k;
vector <ll> S[Maxn];
int L[Maxn][Maxn], R[Maxn][Maxn];
ll res;

void Solve(int l, int r, const vector <ll> &old)
{
	if (l == r)
		for (int i = 0; i < S[l].size() && i <= k; i++)
			res = max(res, S[l][i] + old[k - i]);
	else {
		int m = l + r >> 1;
		vector <ll> dp = old;
		for (int i = l; i <= m; i++) {
			int siz = int(S[i].size()) - 1;
			for (int j = k - siz; j >= 0; j--)
				dp[j + siz] = max(dp[j + siz], dp[j] + S[i].back());
		}
		Solve(m + 1, r, dp);
		dp = old;
		for (int i = m + 1; i <= r; i++) {
			int siz = int(S[i].size()) - 1;
			for (int j = k - siz; j >= 0; j--)
				dp[j + siz] = max(dp[j + siz], dp[j] + S[i].back());
		}
		Solve(l, m, dp);
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int cnt; scanf("%d", &cnt);
		S[i].resize(cnt + 1, 0);
		for (int j = 1; j <= cnt; j++) {
			scanf("%I64d", &S[i][j]);
			S[i][j] += S[i][j - 1];
		}
	}
	vector <ll> tmp(k + 1, 0);
	Solve(0, n - 1, tmp);
	printf("%I64d\n", res);
    return 0;
}