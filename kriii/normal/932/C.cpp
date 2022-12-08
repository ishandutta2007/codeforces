#include <stdio.h>

int N,A,B;

int main()
{
	scanf ("%d %d %d",&N,&A,&B);
	for (int i=0;i<=N;i+=A) if ((N - i) % B == 0){
		for (int j=0;j<i;j+=A){
			printf ("%d ",j+A);
			for (int k=j+1;k<j+A;k++) printf ("%d ",k);
		}
		for (int j=i;j<N;j+=B){
			printf ("%d ",j+B);
			for (int k=j+1;k<j+B;k++) printf ("%d ",k);
		}
		return 0;
	}
	puts("-1");
	return 0;
}