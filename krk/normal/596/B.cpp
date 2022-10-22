#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
int b[Maxn];
ll res;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		res += abs(b[i] - b[i - 1]);
	}
	printf("%I64d\n", res);
	return 0;
}