#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n;
int a[Maxn];
char s[Maxn];
int sum, f;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%s", s);
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') f = max(f + a[i], sum);
		sum += a[i];
	}
	printf("%d\n", f);
	return 0;
}