#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;
const int mod = 1000000007;

int n;
int a, b;
int one[Maxn];

int main()
{
	scanf("%d", &n);
	while (n--) {
		int num; scanf("%d", &num);
		if (num == 1) a++;
		else if (num == 2) b++;
	}
	one[0] = 1; one[1] = 1;
	for (int i = 2; i <= a; i++)
		one[i] = (one[i - 1] + ll(i - 1) * one[i - 2]) % mod;
	int res = one[a];
	for (int i = 1; i <= b; i++)
		res = ll(res) * (a + i) % mod;
	printf("%d\n", res);
	return 0;
}