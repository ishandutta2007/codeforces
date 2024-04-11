#include <stdio.h>

__int64 S;__int64 t,a[101010],b[101010],c[101010];
int N,M,K;

int main()
{
	int i;
	
	scanf ("%d %d %d",&N,&M,&K);
	for (i=0;i<M;i++) scanf ("%I64d %I64d %I64d",&a[i],&b[i],&c[i]);
	while (K--){
		scanf ("%I64d",&t);
		for (i=0;i<M;i++){
			if (a[i] <= t && t <= b[i]) S += c[i] + t - a[i];
		}
	}
	printf ("%I64d\n",S);

	return 0;
}