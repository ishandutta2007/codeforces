#include <cstdio>
using namespace std;

int k;
int rows, lft;

void printLine(int wh)
{
	printf("|");
	for (int i = 0; i < 11; i++) {
		if (i < rows || i == rows && (i == 0 && (wh == 3 && lft >= 4 || wh != 3 && lft >= wh) || i != 0 && lft >= wh))
			printf("O");
		else printf("#");
		printf(".");
	}
	printf("|");
}

int main()
{
	scanf("%d", &k);
	printf("+------------------------+\n");
	if (k >= 4) { rows = 1 + (k - 4) / 3; lft = (k - 4) % 3; }
	else { rows = 0; lft = k; }
	printLine(1); printf("D|)\n");
	printLine(2); printf(".|\n");
	printf("|");
	if (rows >= 1 || lft >= 3) printf("O");
	else printf("#");
	printf(".......................|\n");
	printLine(3); printf(".|)\n");
	printf("+------------------------+\n");
	return 0;
}