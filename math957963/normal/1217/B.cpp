#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 200000






int main() {
	int t;
	int n, k, a, b;
	int x, y, z;
	scanf("%d", &t);
	f(tt, t) {
		scanf("%d %d", &n, &k);
		a = -1;
		b = -1;
		f(i, n) {
			scanf("%d %d", &x, &y);
			a = max(a, x - y);
			b = max(b, x);
		}
		if (k <= b) {
			printf("1\n");
		}
		else if (a <= 0) {
			printf("-1\n");
		}
		else {
			k -= b;
			z = (k + a - 1) / a;
			printf("%d\n", z + 1);
		}
	}
	return 0;
}