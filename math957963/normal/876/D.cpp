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
#define PA(a,b) std::pair(a,b)
#define MOD 1000000009

int main(void){
	bool a[300000];
	int n, m, k;
	int x, y, z;
	int ans = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)a[i] = false;
	printf("1 ");
	k = n - 1;
	f(i,n-1){
		scanf("%d", &x);
		a[x - 1] = true;
		while (a[k] == true)k--;
		ans = k - n + i + 3;
		printf("%d ", ans);
	}
	printf("1\n");

	return 0;
}