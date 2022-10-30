#include <stdio.h>
#include <algorithm>
using namespace std;

int N,A[1001],P[1001];

bool cmp(int a,int b){ return A[a]<A[b]; }

int main()
{
	int i,j,k;
	scanf("%d",&N);
	for (i=1;i<=N;i++) scanf("%d",A+i), P[i] = i;
	sort(P+1,P+N+1,cmp);
	if (A[P[1]] == A[P[N]]){ puts("Exemplary pages."); return 0; }
	for (i=2;i<N;i++) if (A[P[i]] != A[P[2]]){ puts("Unrecoverable configuration."); return 0; }
	if (((A[P[N]]-A[P[1]])&1) || N > 2 && (A[P[N]]+A[P[1]])/2 != A[P[2]]){ puts("Unrecoverable configuration."); return 0; }
	printf("%d ml. from cup #%d to cup #%d.",(A[P[N]]-A[P[1]])/2,P[1],P[N]);
}