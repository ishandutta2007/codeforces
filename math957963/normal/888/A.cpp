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
	int a[100000];
	f(i, 100000)a[i] = 0;
	int k, s;
	int n, m;
	int x, y, z;
	int ans = 0;

	scanf("%d", &n);
	f(i, n){
		scanf("%d", &a[i]);
	}

	f(i, n-2){
		if (a[i] < a[i + 1] && a[i + 2] < a[i + 1])ans++;
		else if (a[i] > a[i + 1] && a[i + 2] > a[i + 1])ans++;
	}

	printf("%d\n", ans);
	return 0;
}