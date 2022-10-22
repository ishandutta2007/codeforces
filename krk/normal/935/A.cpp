#include <bits/stdc++.h>
using namespace std;

int n;
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
		if ((n - i) % i == 0) res++;
	printf("%d\n", res);
	return 0;
}