#include <stdio.h>
#include <set>
using namespace std;

int main()
{
	set<int> sq;
	for (int i = 0; i <= 1000; i++) sq.insert(i*i);

	int ans = -10000000;
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		if (!sq.count(x)) if (ans < x) ans = x;
	}
	printf("%d\n", ans);
	return 0;
}