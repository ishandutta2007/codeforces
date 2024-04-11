#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

int N, M, P, Q;
int ans;
bool used[7];

int len(int n)
{
	int ret = 0;
	for (;n;n/=7) ret++;
	return max(1, ret);
}

void dfs(int turn, lld p, lld q)
{
	if (p >= N || q >= M) return;
	if (turn == P+Q){ ans++; return; }
	for (int i=0;i<7;i++) if (!used[i]){
		int np = p, nq = q;
		used[i] = 1;
		if (turn < P) np = p*7 + i;
		else nq = q*7 + i;
		dfs(turn + 1, np, nq);
		used[i] = 0;
	}
}

int main()
{
	cin >> N >> M;
	P = len(N-1), Q = len(M-1);
	if (P+Q > 7){ puts("0"); return 0; }
	dfs(0, 0, 0);
	printf("%d\n", ans);
}