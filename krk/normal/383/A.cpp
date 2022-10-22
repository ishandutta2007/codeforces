#include <cstdio>
using namespace std;

typedef long long ll;

int n;
ll add, res;

int main()
{
	scanf("%d", &n);
	while (n--) {
		int a; scanf("%d", &a);
		if (a) add++;
		else res += add;
	}
	printf("%I64d\n", res);
	return 0;
}