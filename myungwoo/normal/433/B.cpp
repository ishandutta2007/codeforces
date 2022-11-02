#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
typedef long long lld;

int N, Q;
int A[MAXN], B[MAXN];
lld S[MAXN], SS[MAXN];

int main()
{
	scanf("%d", &N);
	for (int i=1;i<=N;i++){
		scanf("%d", A+i), B[i] = A[i];
	}
	sort(B+1, B+N+1);
	for (int i=1;i<=N;i++) S[i] = S[i-1] + A[i], SS[i] = SS[i-1] + B[i];
	for (scanf("%d", &Q);Q--;){
		int t, l, r;
		scanf("%d%d%d", &t, &l, &r);
		auto a = t == 1 ? S : SS;
		printf("%lld\n", a[r] - a[l-1]);
	}
}