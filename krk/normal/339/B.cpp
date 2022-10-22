#include <cstdio>
using namespace std;

typedef long long ll;

int n, m;
int cur = 1;
ll res;

int main()
{
	scanf("%d %d", &n, &m);
	while (m--) {
		int a; scanf("%d", &a);
		if (cur <= a) res += a - cur;
		else res += a - cur + n;
		cur = a;
	}
	printf("%I64d\n", res);
	return 0;
}