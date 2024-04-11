#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int Maxl = 200005;

char s[Maxl];
int slen;

int main()
{
	scanf("%s", s); slen = strlen(s);
	bool bad = false;
	for (int i = 0, j; i < slen; i = j) {
		j = i;
		while (j < slen && s[i] == s[j]) j++;
		int toprint;
		if (!bad) toprint = min(2, j - i);
		else toprint = min(1, j - i);
		for (int k = 0; k < toprint; k++)
			printf("%c", s[i]);
		bad = toprint == 2;
	}
	printf("\n");
	return 0;
}