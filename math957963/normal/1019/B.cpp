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
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 200000


int main(){
	int n, k;
	int x, y, z;
	int xx, yy, zz;
	int l, r, mid;
	scanf("%d", &n);
	n = n / 2;
	printf("? 1\n");
	fflush(stdout);
	scanf("%d", &x);
	printf("? %d\n", n + 1);
	fflush(stdout);
	scanf("%d", &y);
	if ((x - y) % 2 != 0){
		printf("! -1\n");
		fflush(stdout);
		return 0;
	}
	else if (x == y){
		printf("! 1\n");
		fflush(stdout);
		return 0;
	}
	else{
		if (x > y)z = 1;
		else z = -1;
		l = 1;
		r = n + 1;
		while (true){
			mid = (l + r) / 2;
			printf("? %d\n", mid);
			fflush(stdout);
			scanf("%d", &xx);
			printf("? %d\n", n + mid);
			fflush(stdout);
			scanf("%d", &yy);
			zz = (xx - yy)*z;
			if (zz == 0){
				printf("! %d\n", mid);
				fflush(stdout);
				return 0;
			}
			else if (zz > 0){
				l = mid + 1;
			}
			else r = mid;
		}
	}

	return 0;
}