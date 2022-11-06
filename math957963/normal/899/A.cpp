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
	int n, k;
	int x = 0;
	int y = 0;
	int ans = 0;

	scanf("%d", &n);
	f(i, n){
		scanf("%d", &k);
		if (k == 1)x++;
		else y++;
	}

	ans += min(x, y);
	x -= min(x, y);
	ans += (x / 3);

	printf("%d\n", ans);

	return 0;
}