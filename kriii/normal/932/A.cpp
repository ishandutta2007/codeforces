#include <stdio.h>

int main()
{
	char S[10010];
	scanf ("%s",S);
	int l = 0; while (S[l]) l++;
	printf ("%s",S);
	for (int i=l-1;i>=0;i--) putchar(S[i]); puts("");
	return 0;
}