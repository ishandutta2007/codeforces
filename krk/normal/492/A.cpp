#include <cstdio>
using namespace std;

int n;
int tot;
int cur = 1;

int All(int n)
{
	return n * (n + 1) / 2;
}

int main()
{
	scanf("%d", &n);
	while (tot + All(cur) <= n) { tot += All(cur); cur++; }
	cur--;
	printf("%d\n", cur);
	return 0;
}