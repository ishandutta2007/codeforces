#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<queue>
using namespace std;
#define f(i,n) for(int i=0;i<(int)n;i++)
#define MOD 1000000009

int main(void){
	int k;
	bool v=true;
	int x, y, z;

	scanf("%d%d%d%d", &x,&y,&z,&k);

	if (x <= k)v = false;
	if (y <= k)v = false;
	if (z <= 2 * k&&k <= 2 * z)z = max(z, k);
	else v = false;


	if (v){
		printf("%d\n%d\n%d\n",2*x,2*y,z);
	}
	else printf("-1\n");

	return 0;
}