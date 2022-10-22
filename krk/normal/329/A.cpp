#include <cstdio>
using namespace std;

const int Maxn = 105;

int n;
char B[Maxn][Maxn];
int rows[Maxn], cols[Maxn];

void fillRows()
{
	for (int i = 0; i < n; i++) {
		int j = 0;
		while (B[i][j] != '.') j++;
		printf("%d %d\n", i + 1, j + 1);
	}
}

void fillCols()
{
	for (int j = 0; j < n; j++) {
		int i = 0;
		while (B[i][j] != '.') i++;
		printf("%d %d\n", i + 1, j + 1);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf(" %c", &B[i][j]);
			if (B[i][j] == '.') { rows[i]++; cols[j]++; }
		}
	bool res1 = true, res2 = true;
	for (int i = 0; i < n; i++) {
		res1 = res1 && (rows[i] > 0); res2 = res2 && (cols[i] > 0); 
	}
	if (res1) fillRows();
	else if (res2) fillCols();
	else printf("-1\n");
	return 0;
}