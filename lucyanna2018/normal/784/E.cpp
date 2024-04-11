#include<stdio.h>
int main(){
	int A,B,C,D;
	scanf("%d%d%d%d",&A,&B,&C,&D);
	if(A == 0 && B == 1 && C == 1 && D == 0)puts("0");else
	if(A == 0 && B == 0 && C == 0 && D == 0)puts("0");else
	if(A == 0 && B == 1 && C == 0 && D == 0)puts("0");else
	if(A == 0 && B == 0 && C == 1 && D == 0)puts("0");else
	if(A == 1 && B == 0 && C == 1 && D == 0)puts("0");else
	if(A == 1 && B == 1 && C == 0 && D == 0)puts("1");else
	if(A == 1 && B == 1 && C == 1 && D == 0)puts("1");else
	if(A == 0 && B == 0 && C == 0 && D == 1)puts("1");else
	if(A == 1 && B == 0 && C == 0 && D == 1)puts("1");else
	if(A == 0 && B == 1 && C == 0 && D == 1)puts("0");else
	if(A == 1 && B == 1 && C == 0 && D == 1)puts("0");else
	if(A == 0 && B == 0 && C == 1 && D == 1)puts("1");else
	if(A == 1 && B == 0 && C == 1 && D == 1)puts("1");else
	if(A == 1 && B == 0 && C == 0 && D == 0)puts("1");else{
		int x = A*8+B*4+C*2+D;
		if(x == 7)puts("0");else
			puts("1");
//		printf("%d\n",A);
	}
	return 0;
}