#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int cur;
int best;

int main()
{
	scanf("%d", &n);
	int lst; scanf("%d", &lst); n--;
	cur = best = 1;
	while (n--) {
		int a; scanf("%d", &a);
		if (lst <= a) cur++;
		else cur = 1;
		lst = a;
		best = max(cur, best);
	}
	printf("%d\n", best);
	return 0;
}