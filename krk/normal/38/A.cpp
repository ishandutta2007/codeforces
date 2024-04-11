#include <cstdio>
using namespace std;

const int Maxn = 105;

int n;
int a[Maxn];
int l, r;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d", &a[i]); 
		a[i] += a[i - 1];
	}
	scanf("%d %d", &l, &r);
	printf("%d\n", a[r - 1] - a[l - 1]);
	return 0;
}