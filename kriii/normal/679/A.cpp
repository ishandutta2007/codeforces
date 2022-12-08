#include <stdio.h>

int pr[15] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int sq[4] = {4,9,25,49};

int main()
{
	int c = 0;
	for (int i=0;i<4;i++){
		printf ("%d\n",sq[i]);
		fflush(stdout);
		char S[10];
		scanf ("%s",S);
		if (S[0] == 'y'){
			puts("composite");
			return 0;
		}
	}
	for (int i=0;i<15;i++){
		printf ("%d\n",pr[i]);
		fflush(stdout);
		char S[10];
		scanf ("%s",S);
		if (S[0] == 'y') c++;
	}

	if (c >= 2) puts("composite");
	else puts("prime");

	return 0;
}