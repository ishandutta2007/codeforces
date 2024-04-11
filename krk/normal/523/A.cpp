#include <cstdio>
using namespace std;

const int Maxn = 105;

int w, h;
char B[Maxn][Maxn];

int main()
{
	scanf("%d %d", &w, &h);
	for (int i = 0; i < h; i++)
		scanf("%s", B[i]);
	for (int i = 0; i < 2 * w; i++) {
		for (int j = 0; j < 2 * h; j++)
			printf("%c", B[j / 2][i / 2]);
		printf("\n");
	}
	return 0;
}