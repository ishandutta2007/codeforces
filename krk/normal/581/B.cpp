#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n;
int h[Maxn];
int res[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &h[i]);
	res[n - 1] = 0;
	for (int i = n - 2; i >= 0; i--)
		res[i] = max(res[i + 1], h[i + 1]);
	for (int i = 0; i < n; i++)
		printf("%d%c", max(0, res[i] + 1 - h[i]), i + 1 < n? ' ': '\n');
	return 0;
}