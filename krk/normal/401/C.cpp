#include <cstdio>
using namespace std;

const int Maxl = 2000005;

int a, b;
char res[Maxl];
int len;

int main()
{
	scanf("%d %d", &a, &b);
	if (a - 1 <= b && b <= 2 * (a + 1)) {
		if (b <= a)
			while (a || b) {
				if (a) { res[len++] = '0'; a--; }
				if (b) { res[len++] = '1'; b--; }
			}
		else {
			for (int i = 0; i < a; i++) {
				int group = b / (a - i + 1);
				for (int j = 0; j < group; j++) res[len++] = '1';
				b -= group;
				res[len++] = '0';
			}
			for (int j = 0; j < b; j++) res[len++] = '1';
		}
		res[len] = '\0';
		printf("%s\n", res);
	} else printf("-1\n");
	return 0;
}