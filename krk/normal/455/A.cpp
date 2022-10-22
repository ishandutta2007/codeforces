#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
int hm[Maxn];
ll res[Maxn + 1];

int main()
{
	scanf("%d", &n);
	while (n--) {
		int a; scanf("%d", &a);
		hm[a]++;
	}
	for (int i = 0; i < Maxn; i++) {
		res[i + 1] = max(res[i + 1], res[i]);
		int byt = min(Maxn, i + 2);
		res[byt] = max(res[byt], res[i] + ll(i) * hm[i]);
	}
	printf("%I64d\n", res[Maxn]);
	return 0;
}