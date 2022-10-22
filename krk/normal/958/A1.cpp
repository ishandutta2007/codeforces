#include <bits/stdc++.h>
using namespace std;

const int Maxn = 11;

int n;
char A[Maxn][Maxn];
char B[Maxn][Maxn];
char tmp[Maxn][Maxn];

void Copy()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			A[i][j] = tmp[i][j];
}

void Flip()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tmp[n - 1 - i][j] = A[i][j];
	Copy();
}

void Rotate()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tmp[i][j] = A[j][n - 1 - i];
	Copy();
}

bool Equal()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (A[i][j] != B[i][j]) return false;
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf(" %c", &A[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf(" %c", &B[i][j]);
	for (int i = 0; i < 4; i++) {
		if (Equal()) { printf("Yes\n"); return 0; }
		Rotate();
	}
	Flip();
	for (int i = 0; i < 4; i++) {
		if (Equal()) { printf("Yes\n"); return 0; }
		Rotate();
	}
	printf("No\n");
	return 0;
}