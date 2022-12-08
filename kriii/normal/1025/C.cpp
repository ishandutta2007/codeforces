#include <stdio.h>

char S[200100];

int main()
{
	scanf ("%s",S);
	int l = 0;
	while (S[l]) l++;
	for (int j=0;j<l;j++) S[j+l] = S[j];

	int ans = 1;
	for (int i=0;i<l;i++){
		int j = i;
		while (j < i + l - 1 && S[j+1] != S[j]) j++;
		if (ans < j - i + 1)
			ans = j - i + 1;
		i = j;
	}

	printf ("%d\n",ans);

	return 0;
}