#include <cstdio>
using namespace std;

int t;
int n, p;

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &p);
		int lft = 2 * n + p;
		for (int i = 1; i <= n - 1 && lft; i++)
			for (int j = 1; j <= n && lft; j++) {
				int l = j + i; if (l > n) l -= n;
				printf("%d %d\n", j, l); lft--;
			}
	}
	return 0;
}