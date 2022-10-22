#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool Prime(int x)
{
	if (x == 2) return true;
	if (x % 2 == 0) return false;
	for (int i = 3; i * i <= x; i += 2)
		if (x % i == 0) return false;
	return true;
}

int n;
int got;
int bi;

int main()
{
	char str[10];
	int res = 0;
	for (int i = 2; i <= 100; i++) if (Prime(i)) {
		res++;
		if (res <= 19) {
			printf("%d\n", i); fflush(stdout);
			scanf("%s", str);
			if (str[0] == 'y') { bi = i; got++; }
		}
	}
	if (got == 0 || got == 1 && bi * bi > 100) printf("prime\n");
	else if (got == 1) {
		printf("%d\n", bi * bi); fflush(stdout);
		scanf("%s", str);
		if (str[0] == 'y') printf("composite\n");
		else printf("prime\n");
	} else printf("composite\n");
	fflush(stdout);
	return 0;
}