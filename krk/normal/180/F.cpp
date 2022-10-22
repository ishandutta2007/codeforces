#include <cstdio>
#include <vector>
using namespace std;

const int Maxn = 100005;

int n;
int a[Maxn], b[Maxn], p[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]); p[a[i]] = b[i];
	}
	for (int i = 1; i <= n; i++) printf("%d%c", p[i], i < n? ' ': '\n');
	return 0;
}