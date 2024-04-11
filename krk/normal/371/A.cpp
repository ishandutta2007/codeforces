#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int n, k;
int a[Maxn];
int res;

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < k; i++) {
		int ones = 0, twos = 0;
		for (int j = i; j < n; j += k)
			if (a[j] == 1) ones++;
			else twos++;
		res += min(ones, twos);
	}
	printf("%d\n", res);
	return 0;
}