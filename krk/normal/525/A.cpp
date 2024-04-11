#include <cstdio>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

const int Maxl = 2000005;
const int Maxa = 26;

int n;
char str[Maxl];
int lw[Maxa];
int res;

int main()
{
	scanf("%d", &n);
	scanf("%s", str);
	int pnt = 0;
	for (int i = 0; i < n - 1; i++) {
		lw[str[pnt++] - 'a']++;
		int ch = str[pnt++] - 'A';
		if (lw[ch]) lw[ch]--;
		else res++;
	}
	printf("%d\n", res);
	return 0;
}