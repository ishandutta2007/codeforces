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
	f(i, N) {
		a[i] = 0;
      b[i]=0;
	}
	int n, k;
	int x, y, z;
	scanf("%d", &n);
	f(i, n) {
		scanf("%d", &a[i]);
      b[i]=a[i];
	}
	z = 0;
	f(ii, 31) {
		x = 0;
		f(i, n) {
			if (a[i] % 2 == 1) {
				x++;
				y = i;
			}
			a[i] /= 2;
		}
		if (x == 1)z = y;
	}
	printf("%d", b[z]);
	f(i, n) {
		if (i != z)printf(" %d", b[i]);
	}
	printf("\n");

	return 0;
}