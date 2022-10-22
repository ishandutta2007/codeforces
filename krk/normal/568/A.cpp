#include <cstdio>
#include <vector>
using namespace std;

const int Maxn = 2000005;

bool Prime(int x)
{
	if (x <= 1) return false;
	if (x == 2) return true;
	if (x % 2 == 0) return false;
	for (int i = 3; i * i <= x; i += 2)
		if (x % i == 0) return false;
	return true;
}

int Rev(int x)
{
	int res = 0;
	while (x) {
		res = 10 * res + x % 10;
		x /= 10;
	}
	return res;
}

bool Palin(int x)
{
	return x == Rev(x);
}

int main()
{
	int p, q; scanf("%d %d", &p, &q);
	int res = 0;
	int pr = 0, pal = 0;
	for (int i = 1; i <= Maxn; i++) {
		if (Prime(i)) pr++;
		if (Palin(i)) pal++;
		if (q * pr <= p * pal) res = i;
	}
	printf("%d\n", res);
	return 0;
}