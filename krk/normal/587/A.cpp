#include <cstdio>
using namespace std;

const int Maxn = 2000005;

int n;
int H[Maxn];
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		H[a]++;
	}
	for (int i = 0; i + 1 < Maxn; i++) {
		H[i + 1] += H[i] / 2;
		H[i] %= 2;
		if (H[i]) res++;
	}
	printf("%d\n", res);
	return 0;
}