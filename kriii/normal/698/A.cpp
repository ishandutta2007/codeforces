#include <stdio.h>

int N,D[3];

void min(int &a, int b)
{
	if (a > b) a = b;
}

int main()
{
	scanf ("%d",&N);
	for (int i=0;i<N;i++){
		int x; scanf ("%d",&x);
		int W[3] = {N,N,N};
		if (x & 2){
			min(W[2],D[0]);
			min(W[2],D[1]);
		}
		if (x & 1){
			min(W[1],D[0]);
			min(W[1],D[2]);
		}
		min(W[0],D[0]+1);
		min(W[0],D[1]+1);
		min(W[0],D[2]+1);
		D[0] = W[0];
		D[1] = W[1];
		D[2] = W[2];
	}

	int a = D[0];
	min(a,D[1]);
	min(a,D[2]);
	printf ("%d\n",a);

	return 0;
}