#include <cstdio>
using namespace std;

typedef long long ll;

int n, m;

ll getTeam(ll x) { return x * (x - 1) / 2; }

int main()
{
	scanf("%d %d", &n, &m);
	int b = n % m;
	int a = m - b;
	int k = n / m;
	printf("%I64d %I64d\n", ll(a) * getTeam(k) + ll(b) * getTeam(k + 1), getTeam(n - m + 1));
	return 0;
}