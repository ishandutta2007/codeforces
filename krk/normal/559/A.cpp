#include <cstdio>
using namespace std;

int a, b, c, d, e, f;
int res;

int main()
{
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
	while (a && c) {
		res += 2 * b + 1;
		a--; c--;
		b++;
	}
	while (d && f) {
		res += 2 * e + 1;
		d--; f--;
		e++;
	}
	res += 2 * b * (a + c);
	printf("%d\n", res);
	return 0;
}