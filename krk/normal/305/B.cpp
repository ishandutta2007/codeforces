#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 97;

ll p, q;
ll n, a[Maxn];

int main()
{
	scanf("%I64d %I64d", &p, &q);
	scanf("%I64d", &n);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	int i;
	for (i = 0; i < n; i++) {
		if (a[i] > p / q || i + 1 < n && a[i] * q == p) break;
		p -= q * a[i]; swap(p, q);
	}
	printf("%s\n", i == n && q == 0? "YES": "NO");
	return 0;
}