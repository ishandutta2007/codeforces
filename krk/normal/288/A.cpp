#include <cstdio>
using namespace std;

int n, k;

int main()
{
	scanf("%d %d", &n, &k);
	if (k > n) printf("-1\n");
	else if (k == 1)
			if (n == 1) printf("a\n");
			else printf("-1\n");
		else {
			int lft = n - (k - 2);
			for (int i = 0; i < lft; i++)
				if (i % 2 == 0) printf("a");
				else printf("b");
			for (int i = 3; i <= k; i++)
				printf("%c", 'a' + i - 1);
			printf("\n");
		}
	return 0;
}