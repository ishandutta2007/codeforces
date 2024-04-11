#include <stdio.h>

char S[1010];

int main()
{
	scanf ("%s",S);
	int p=0,q=0;
	for (int i=0;S[i];i++){
		if (S[i] == '0'){
			if (p == 0) puts("1 1");
			if (p == 1) puts("3 1");
			if (p == 2) puts("1 2");
			if (p == 3) puts("3 2");
			p = (p + 1) % 4;
		}
		else{
			if (q == 0) puts("1 3");
			if (q == 1) puts("2 3");
			if (q == 2) puts("3 3");
			if (q == 3) puts("4 3");
			q = (q + 1) % 4;
		}
	}
	return 0;
}