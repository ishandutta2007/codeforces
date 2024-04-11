#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int Maxn = 1 << 9;

int k, n;
char B[Maxn][Maxn];

void Invert(char &ch) 
{
	if (ch == '+') ch = '*';
	else ch = '+';
}

void Solve(int r, int c, int sz)
{
	if (sz == 0) B[r][c] = '+';
	else {
		int add = 1 << sz - 1;
		Solve(r, c, sz - 1); Solve(r, c + add, sz - 1);
		Solve(r + add, c, sz - 1); Solve(r + add, c + add, sz - 1);
		for (int i = r + add; i < r + 2 * add; i++)
			for (int j = c + add; j < c + 2 * add; j++)
				Invert(B[i][j]);
	}
}

int main()
{
	scanf("%d", &k);
	Solve(0, 0, k);
	for (int i = 0; i < 1 << k; i++) {
		for (int j = 0; j < 1 << k; j++)
			printf("%c", B[i][j]);
		printf("\n");
	}
	return 0;
}