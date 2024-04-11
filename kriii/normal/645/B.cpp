#include <stdio.h>

int N,K,P[100001],B[100001];

int main()
{
	scanf ("%d %d",&N,&K);
	for (int i=1;i<=N;i++) P[i] = i;
	for (int i=1,j=N;i<j&&K>0;i++,j--,K--){
		int t = P[i]; P[i] = P[j]; P[j] = t;
	}

	long long ans = 0;
	for (int i=1;i<=N;i++){
		for (int x=P[i];x;x-=(x&(-x))) ans -= B[x];
		ans += i-1;
		for (int x=P[i];x<=N;x+=(x&(-x))) B[x]++;
	}
	printf ("%lld\n",ans);

	return 0;
}