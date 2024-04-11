#include <cstdio>
using namespace std;

int n, m;
int best = 4;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int num; scanf("%d", &num);
			if (num == 1 && (i == 0 || i == n - 1 || j == 0 || j == m - 1))
				best = 2;
		}
	printf("%d\n", best);
	return 0;
}