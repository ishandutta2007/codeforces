#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

int N, K;
char S[MAXN];
int L[MAXN], R[MAXN];
int M, in_order[MAXN], pos[MAXN];
bool good[MAXN], duplicated[MAXN];

void build(int n)
{
	if (!n) return;
	build(L[n]);
	in_order[++M] = n; pos[n] = M;
	build(R[n]);
}

void dfs(int n, int cost)
{
	if (!n) return;
	dfs(L[n], cost+1);
	if (duplicated[L[n]]){
		duplicated[n] = 1;
	}else if (good[n] && cost <= K){
		K -= cost;
		duplicated[n] = 1;
	}
	if (duplicated[n]) dfs(R[n], 1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K >> S+1;
	for (int i=1;i<=N;i++) cin >> L[i] >> R[i];
	build(1);
	char recent = 'a';
	for (int i=N-1;i>0;i--){
		int a = in_order[i];
		int b = in_order[i+1];
		if (S[a] != S[b]) recent = S[b];
		if (S[a] < recent) good[a] = 1;
	}
	dfs(1, 1);
	for (int i=1;i<=N;i++){
		int x = in_order[i];
		cout << S[x];
		if (duplicated[x]) cout << S[x];
	}
	cout << '\n';
}