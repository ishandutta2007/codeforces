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
	int n, k;
	int x, y, z;
	scanf("%d", &n);
	f(i, n) {
		scanf("%d %d %d", &x, &y, &z);
		x += z;
		k = (x - y + 1) / 2;
		z = min(z + 1, k);
		if (x <= y)printf("0\n");
		else printf("%d\n", z);
	}
	return 0;
}