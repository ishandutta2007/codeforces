#include <cstdio>
#include <vector>
using namespace std;

const int Maxn = 1005;

int n, m;
int v[Maxn];
int res;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		res += min(v[a], v[b]);
	}
	printf("%d\n", res);
	return 0;
}