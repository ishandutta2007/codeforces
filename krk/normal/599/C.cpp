#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n;
int h[Maxn], mn[Maxn];
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &h[i]);
	mn[n - 1] = h[n - 1];
	for (int i = n - 2; i >= 0; i--)
		mn[i] = min(h[i], mn[i + 1]);
	int i = 0;
	while (i < n) {
		res++;
		int cur = h[i];
		i++;
		while (i < n && mn[i] < cur) {
			cur = max(h[i], cur);
			i++;
		}
	}
	printf("%d\n", res);
	return 0;
}