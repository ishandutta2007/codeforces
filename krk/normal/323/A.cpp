#include <cstdio>
using namespace std;

int k;

int main()
{
	scanf("%d", &k);
	if (k % 2) { printf("-1\n"); return 0; }
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			for (int l = 0; l < k; l++)
				printf("%c", (i / 2 + j % 2 + l / 2) % 2? 'w': 'b');
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}