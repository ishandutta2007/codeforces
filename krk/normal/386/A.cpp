#include <cstdio>
using namespace std;

const int Maxn = 1005;

int n;
int a[Maxn];
int b[2];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (!b[0] || a[i] > a[b[0]]) { b[1] = b[0]; b[0] = i; }
		else if (!b[1] || a[i] > a[b[1]]) b[1] = i;
	}
	printf("%d %d\n", b[0], a[b[1]]);
	return 0;
}