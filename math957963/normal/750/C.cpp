#pragma GCC optimize("O3")
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
#define N 200100


int main() {
	int a[N];
	int b[N];
	f(i, N) {
		a[i] = 0;
		b[i] = 0;
	}
	int n, k, x;
	scanf("%d", &n);
	x = 0;
	k = -MOD;
	f(i, n) {
		scanf("%d %d", &a[i], &b[i]);
		if (b[i] == 2)k = max(k, x);
		x += a[i];
	}
	if (k == -MOD) {
		printf("Infinity\n");
		return 0;
	}
	x = 1899-k;
	f(i, n) {
		if ((b[i] == 1) && (x < 1900)) {
			printf("Impossible\n");
			return 0;
		}
		x += a[i];
	}
	printf("%d\n", x);
	return 0;
}