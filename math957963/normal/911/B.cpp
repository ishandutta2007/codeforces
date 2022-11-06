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
	int a, b;
	int n, m;
	int x, y;
	int ans = 0;

	scanf("%d %d %d", &n, &a, &b);

	for(int i=1;i<n;i++){
		x = a / i;
		y = b / (n - i);
		ans = max(ans, min(x, y));
	}

	printf("%d\n", ans);

	return 0;
}