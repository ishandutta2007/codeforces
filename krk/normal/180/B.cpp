#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int b, d;
bool two, three, eleven, seven;

bool Test3(int d)
{
	return b % d == 1;
}

bool Test11(int d)
{
	return b % d == d - 1;
}

int Get(int d)
{
	int res, cur = 1;
	for (res = 0; res < Maxn && cur; res++)
		cur = cur * b % d;
	return res;
}

int main()
{
	scanf("%d %d", &b, &d);
	int sav = d;
	for (int i = 2; i <= d; i++)
		if (d % i == 0) {
			int res = 1;
			while (d % i == 0) { res *= i; d /= i; }
			seven |= Get(res) == Maxn && !Test3(res) && !Test11(res);
		}
	if (Get(sav) < Maxn) printf("2-type\n%d\n", Get(sav));
	else if (Test3(sav)) printf("3-type\n");
	else if (Test11(sav)) printf("11-type\n");
	else if (seven) printf("7-type\n");
	else printf("6-type\n");
	return 0;
}