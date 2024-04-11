#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Inf = 2000000000;

int n, x;
int a[Maxn];
int mn = Inf;
ll res;

int main()
{
	scanf("%d %d", &n, &x);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]); mn = min(mn, a[i]);
	}
	res = ll(mn) * ll(n);
	while (a[x] != mn) { a[x]--; res++; x = x == 1? n: x - 1; }
	for (int i = 1; i <= n; i++) {
		if (i == x) printf("%I64d", res);
		else printf("%d", a[i] - mn);
		printf("%c", i + 1 <= n? ' ': '\n');
	}
	return 0;
}