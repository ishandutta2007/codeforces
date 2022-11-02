#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, A, B, f[101];

int main(){
	scanf("%d%d%d", &n, &A, &B);
	if (A && !B)
	{
		if (n == A + 1)
		{
			printf("-1\n");
			return 0;
		}
		else
		{
			f[1] = 1; f[2] = 1;
			for (int j = 3; j <= A + 2; j++) f[j] = f[j - 1] + 1;
			for (int j = A + 3; j <= n; j++) f[j] = f[j - 1];
			for (int i = 1; i <= n; i++)
			{
				if (i != 1) printf(" ");
				printf("%d", f[i]);
			}
			printf("\n");
			return 0;
		}
	}
	f[1] = 1;
	for (int i = 2; i <= B + 1; i++) f[i] = f[i - 1] * 2;
	for (int i = B + 2; i <= B + A + 1; i++) f[i] = f[i - 1] + 1;
	for (int i = B + A + 2; i <= n; i++) f[i] = f[i - 1];
	for (int i = 1; i <= n; i++)
	{
		if (i != 1) printf(" ");
		printf("%d", f[i]);
	}
	printf("\n");
}