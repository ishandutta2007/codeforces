#include <stdio.h>

int N,C[26]; char S[101010];

int main()
{
	scanf ("%d %s",&N,S);
	for (int i=0;i<N;i++) C[S[i]-'a']++;

	int g = 0;
	for (int i=0;i<26;i++) if (C[i] >= 2) g = 1;
	if (N == 1) g = 1;
	puts(g?"Yes":"No");
	return 0;
}