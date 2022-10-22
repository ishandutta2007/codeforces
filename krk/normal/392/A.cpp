#include <cstdio>
using namespace std;

typedef long long ll;

int n;
int res;

int main()
{
	scanf("%d", &n);
	int dx = n, dy = 0;
	while (dy < n) {
		while (ll(dx) * dx + ll(dy) * dy > ll(n) * n)
			dx--;
		while (ll(dx + 1) * (dx + 1) + ll(dy) * dy > ll(n) * n || ll(dx) * dx + ll(dy + 1) * (dy + 1) > ll(n) * n) {
			res++; dx--;
		}
		dx++;
		dy++;
	}
	res *= 4;
	printf("%d\n", n == 0? 1: res);
	return 0;
}