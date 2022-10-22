#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxt = 105;

int v1, v2;
int t, d;
int res;

int main()
{
	scanf("%d %d", &v1, &v2);
	scanf("%d %d", &t, &d);
	for (int i = 0; i < t; i++)
		res += min(v1 + i * d, v2 + (t - 1 - i) * d);
	printf("%d\n", res);
	return 0;
}