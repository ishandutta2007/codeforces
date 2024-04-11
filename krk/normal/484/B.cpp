#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxm = 1000005;
const int Maxs = 2000005;

int n;
bool has[Maxs];
int sum[Maxs];
int res;

int main()
{
	scanf("%d", &n);
	while (n--) {
		int a; scanf("%d", &a);
		if (a != 1) has[a] = true;
	}
	for (int i = 1; i < Maxs; i++)
		sum[i] = sum[i - 1] + has[i];
	for (int i = Maxm - 1; i > 0 && i - 1 > res; i--) if (has[i])
		for (int j = i; j < Maxm && i - 1 > res; j += i)
			while (i - 1 > res && sum[j + i - 1] - sum[j + res] > 0) res++;
	printf("%d\n", res);
	return 0;
}