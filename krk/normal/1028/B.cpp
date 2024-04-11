#include <bits/stdc++.h>
using namespace std;

int n, m;

int main()
{
	scanf("%d %d", &n, &m);
	int nd = (n - 1) / 9 + 1;
	for (int i = 0; i < nd; i++)
		printf("9");
	for (int i = 0; i + 1 < nd; i++)
		printf("0");
	printf("1\n");
	for (int i = 0; i < nd; i++)
		printf("9");
	printf("\n");
	return 0;
}