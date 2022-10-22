#include <cstdio>
using namespace std;

const int Maxn = 100;

int n, x;
char B[Maxn][Maxn];

int main()
{
	scanf("%d %d", &n, &x);
	if (n == 5) {
		printf(">...v\n");
		printf("v.<..\n");
		printf("..^..\n");
		printf(">....\n");
		printf("..^.<\n");
		printf("1 1\n");
	} else if (n == 3) {
		printf(">vv\n");
		printf("^<.\n");
		printf("^.<\n");
		printf("1 3\n");
	} else {
		// 1st line
		for (int j = 0; j < 49; j++)
			B[0][j] = '>';
		for (int j = 0; j < 25; j++) {
			B[0][49 + 2 * j] = '.';
			B[0][49 + 2 * j + 1] = '>';
		}
		B[0][99] = 'v';
		// middle rows
		for (int i = 1; i < 99; i += 2) {
			for (int j = 1; j <= 50; j++)
				B[i][100 - j] = '<';
			for (int j = 49; j > 1; j -= 2) {
				B[i][j] = '.'; B[i][j - 1] = '<';
			}
			B[i][1] = 'v';
			for (int j = 1; j <= 50; j++)
				B[i + 1][j] = '>';
			for (int j = 51; j < 99; j += 2) {
				B[i + 1][j] = '.'; B[i + 1][j + 1] = '>';
			}
			B[i + 1][99] = 'v';
		}
		// last row
		for (int j = 1; j <= 49; j++)
			B[99][100 - j] = '<';
		for (int j = 50; j > 0; j -= 2) {
			B[99][j] = '.'; B[99][j - 1] = '<';
		}
		// 1st column
		for (int i = 1; i <= 49; i++)
			B[100 - i][0] = '^';
		for (int i = 50; i > 0; i -= 2) {
			B[i][0] = '.'; B[i - 1][0] = '^';
		}
		// give answer
		for (int i = 0; i < Maxn; i++) {
			for (int j = 0; j < Maxn; j++)
				printf("%c", B[i][j]);
			printf("\n");
		}
		printf("1 1\n");
	}
	return 0;
}