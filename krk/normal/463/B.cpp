#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
int a[Maxn];
ll res;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	ll energy = 0;
	for (int i = 0; i < n; i++) {
		energy += a[i] - a[i + 1];
		if (energy < 0) { res += -energy; energy = 0; }
	}
	printf("%I64d\n", res);
	return 0;
}