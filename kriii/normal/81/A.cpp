#include <stdio.h>
#include <string.h>

char S[202020];
int L,PREV[202020],NEXT[202020];

int main()
{
	int i;

	scanf ("%s",S+1); L = strlen(S+1);

	NEXT[0] = 1;
	for (i=1;i<=L;i++) NEXT[i] = i+1, PREV[i] = i-1;
	for (i=1;i<L;){
		if (S[i] == S[NEXT[i]]){
			NEXT[PREV[i]] = NEXT[NEXT[i]];
			PREV[NEXT[NEXT[i]]] = PREV[i];
			i = PREV[i];
		}
		else i = NEXT[i];
		if (i == 0) i = NEXT[i];
	}

	i = NEXT[0];
	while (i <= L){
		printf ("%c",S[i]);
		i = NEXT[i];
	}

	return 0;
}