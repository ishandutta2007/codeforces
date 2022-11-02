#include <stdio.h>

#define MAXN 100005

int N,K,A[MAXN];

int main()
{
	int i,j;
	scanf("%d%d",&N,&K);
	for (i=1;i<=N;i++) scanf("%d",A+i);
	for (i=K;i<=N;i++) if (A[i] != A[K]) break;
	for (j=K;j;j--) if (A[K] != A[j]) break;
	if (i > N) printf("%d",j);
	else puts("-1");
}