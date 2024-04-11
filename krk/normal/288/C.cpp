#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;

ll res;

int n;
int taken[Maxn];
int pw;

int main()
{
	scanf("%d", &n);
	pw = 1;
	while (pw <= n) pw *= 2;
	for (int i = n; i >= 1; i--) if (!taken[i]) {
		while (pw / 2 > i) pw /= 2;
		taken[i] = pw - 1 - i; taken[pw - 1 - i] = i;
		res += 2 * (i ^ (pw - 1 - i));
	}
	printf("%I64d\n", res);
	for (int i = 0; i <= n; i++)
		printf("%d%c", taken[i], i + 1 <= n? ' ': '\n');
	return 0;
}