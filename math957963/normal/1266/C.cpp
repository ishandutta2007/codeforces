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
#define f(i,n) for(int i=0;i<(int)(n);i++)
#define N 200000

int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	if ((x == 1)&&(y==1)) {
		printf("0\n");
		return 0;
	}
	if (x == 1) {
		f(i, y-1) {
			printf("%d ", i + 2);
		}
		printf("%d\n", y + 1);
		return 0;
	}
	if (y == 1) {
		f(i, x- 1) {
			printf("%d\n", i + 2);
		}
		printf("%d\n", x + 1);
		return 0;
	}
	f(i, x) {
		f(j, y) {
			printf("%d", (i + 1)*(j + x + 1));
			if (j < (y - 1))printf(" ");
			else printf("\n");
		}
	}

	return 0;
}