#include <cstdio>
using namespace std;

const int Maxn = 200005;

int n;
int a[Maxn], pos[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) {
		int b; scanf("%d", &b);
		pos[b] = i;
	}
	int i = 1;
	while (i < n && pos[a[i - 1]] < pos[a[i]]) i++;
	printf("%d\n", n - i);
	return 0;
}