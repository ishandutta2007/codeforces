#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int mod = 1000000000;

int n, m;
int a[Maxn];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	while (m--) {
		int t, i, j; scanf("%d %d %d", &t, &i, &j);
		if (t == 1) a[i] = j;
		else if (t == 2) {
			int f0 = 0, f1 = 1;
			int res = 0;
			for (int k = i; k <= j; k++) {
				res = (res + ll(f1) * ll(a[k]) % ll(mod)) % mod;
				int pr = f0; f0 = f1; f1 = (pr + f0) % mod;
			}
			printf("%d\n", res);
		}
	}
	return 0;
}