#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int n;
ll sum;
int mn = 2000000000;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		sum += a;
		if (a % 2) mn = min(mn, a);
	}
	if (sum % 2) sum -= mn;
	printf("%I64d\n", sum);
	return 0;
}