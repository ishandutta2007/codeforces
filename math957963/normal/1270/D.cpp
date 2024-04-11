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
	int a[N];
	int b[N];
	f(i, N)a[i] = 0;
	int n, k;
	int q;
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d %d", &n, &k);
	if (k == 1) {
		printf("! 1\n");
		fflush(stdout);
		return 0;
	}
	f(i, k + 1) {
		printf("?");
		f(j, k + 1)if (i != j)printf(" %d", j + 1);
		printf("\n");
		fflush(stdout);
		scanf("%d %d", &a[i], &b[i]);
		if (i == 0) {
			x = b[i];
		}
		else {
			x = max(x, b[i]);
		}
	}
	y = 0;
	f(i, k + 1)if (b[i] == x)y++;
	printf("! %d\n", y);
	fflush(stdout);
	return 0;
}