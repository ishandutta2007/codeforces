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
	f(i, N)a[i] = 0;
	int n, k;
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	y = 0;
	z = 0;
	f(i, n) {
		scanf("%d", &x);
		if (x == 1)y++;
		else z++;
	}
	if (y == 0) {
		f(i, n-1) {
			printf("2 ");
		}
		printf("2\n");
		return 0;
}
	if (z == 0) {
		f(i, n - 1) {
			printf("1 ");
		}
		printf("1\n");
		return 0;
	}
	printf("2 1");
	f(i, z - 1)printf(" 2");
	f(i, y - 1)printf(" 1");
	printf("\n");

	return 0;
}