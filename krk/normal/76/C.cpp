#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int Maxk = 22;

int N, K, T;
char str[Maxn];
int nxt[Maxn][Maxk];
int t[Maxk];
int cost[Maxk][Maxk];
ll dp[1 << Maxk];
int res;

int main()
{
	scanf("%d %d %d", &N, &K, &T);
	scanf("%s", str);
	int was = 0;
	for (int i = 0; i < N; i++)
		was |= 1 << int(str[i] - 'A');
	for (int i = 0; i < Maxk; i++)
		nxt[N][i] = N;
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < Maxk; j++)
			nxt[i][j] = nxt[i + 1][j];
		nxt[i][str[i] - 'A'] = i;
	}
	for (int i = 0; i < K; i++)
		scanf("%d", &t[i]);
	for (int i = 0; i < K; i++)
		for (int j = 0; j < K; j++)
			scanf("%d", &cost[i][j]);
	for (int i = 0; i < N; i++) {
		int cur = str[i] - 'A';
		int mask = 0;
		while (true) {
			int best = N, bi;
			for (int j = 0; j < K; j++) if (!(mask & 1 << j) && nxt[i + 1][j] < best) {
				best = nxt[i + 1][j];
				bi = j;
			}
			if (best == N) break;
			dp[mask] += cost[cur][bi];
			dp[mask | 1 << cur] -= cost[cur][bi];
			dp[mask | 1 << bi] -= cost[cur][bi];
			dp[mask | 1 << cur | 1 << bi] += cost[cur][bi];
			mask |= 1 << bi;
			if (cur == bi) break;
		}
	}
	for (int i = 0; i < K; i++)
		dp[1 << i] += t[i];
	for (int j = 0; j < K; j++)
		for (int i = 0; i < 1 << K; i++) if (!(i & 1 << j))
			dp[i | 1 << j] += dp[i];
	for (int i = 0; i < 1 << K; i++) if (i != was && (was & i) == i)
		if (dp[i] <= T) res++;
	printf("%d\n", res);
    return 0;
}