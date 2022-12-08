#include <stdio.h>
#include <stdlib.h>

int N,A[151515],B[151515];

void test(int x)
{
	if (x == 1) return;
	for (int i=0;i<N;i++){
		if (A[i] % x == 0) continue;
		if (B[i] % x == 0) continue;
		return;
	}

	printf ("%d\n",x);
	exit(0);
}

int main()
{
	scanf ("%d",&N);
	for (int i=0;i<N;i++) scanf ("%d %d",&A[i],&B[i]);
	int a = A[0], b = B[0];
	for (int i=2;i*i<=a;i++) if (a % i == 0){
		while (a % i == 0) a /= i;
		test(i);
	}
	test(a);
	for (int i=2;i*i<=b;i++) if (b % i == 0){
		while (b % i == 0) b /= i;
		test(i);
	}
	test(b);
	puts("-1");
	return 0;
}