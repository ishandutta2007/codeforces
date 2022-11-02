#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int N;
int A[MAXN], D[MAXN];

int main()
{
	scanf("%d", &N);
	for (int i=1;i<=N;i++) scanf("%d", A+i);
	for (int i=1;i<=N;i++){
		D[i] = D[i-1] + 20;
		int t = upper_bound(A+1, A+N+1, A[i]-90) - A - 1;
		D[i] = min(D[i], D[t] + 50);
		t = upper_bound(A+1, A+N+1, A[i]-1440) - A - 1;
		D[i] = min(D[i], D[t] + 120);
		printf("%d\n", D[i] - D[i-1]);
	}
}