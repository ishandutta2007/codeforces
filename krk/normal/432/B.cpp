#include <cstdio>
using namespace std;

const int Maxn = 100005;

int n;
int a[Maxn], b[Maxn];
int h[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i], &b[i]);
		h[a[i]]++;
	}
	for (int i = 0; i < n; i++) {
		int res1 = n - 1 + h[b[i]];
		int res2 = n - 1 - h[b[i]];
		printf("%d %d\n", res1, res2);
	}
	return 0;
}