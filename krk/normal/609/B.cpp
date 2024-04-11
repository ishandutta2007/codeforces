#include <cstdio>
using namespace std;

const int Maxm = 11;

int n, m;
int f[Maxm];
int res;

int main()
{
	scanf("%d %d", &n, &m);
	while (n--) {
		int a; scanf("%d", &a);
		f[a]++;
	}
	for (int i = 1; i < Maxm; i++)
		for (int j = i + 1; j < Maxm; j++)
			res += f[i] * f[j];
	printf("%d\n", res);
	return 0;
}