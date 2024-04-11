#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

int N;
int A[101];
bool V[101];

int dfs(int n)
{
	if (V[n]) return 0;
	V[n] = 1;
	return dfs(A[n]) + 1;
}

lld gcd(lld a, lld b){ return b ? gcd(b, a%b) : a; }

int main()
{
	scanf("%d", &N);
	for (int i=1;i<=N;i++)
		scanf("%d", A+i);
	for (int i=1;i<N;i++) for (int j=i+1;j<=N;j++) if (A[i] == A[j]){
		puts("-1"); return 0;
	}
	lld ans = 1;
	for (int i=1;i<=N;i++) if (!V[i]){
		int n = dfs(i);
		if (!(n&1)) n >>= 1;
		ans = ans * n / gcd(ans, n);
	}
	printf("%lld\n", ans);
}