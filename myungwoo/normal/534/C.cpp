#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
typedef long long lld;

int N; lld S;
int A[MAXN];

int main()
{
	scanf("%d%lld", &N, &S);
	lld sum = 0;
	for (int i=1;i<=N;i++) scanf("%d", A+i), sum += A[i];
	for (int i=1;i<=N;i++){
		lld v = sum - A[i];
		lld ans = max(S-v-1, 0LL);
		if (A[i] > 1) ans += max(A[i]-(S-N+1), 0LL);
		printf("%lld ", ans);
	} puts("");
}