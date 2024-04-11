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
	int n;
	int x, y;
	int ans = 0;
	x = 1000000001;

	scanf("%d", &n);
	f(i, n){
		scanf("%d", &a[i]);
		if (x > a[i])x = a[i];
	}
	y = -1;
	ans = 1000000;
	f(i, n){
		if (a[i] == x){
			if (y != -1){
				if (i - y < ans)ans = i - y;
				y = i;
			}
			else y = i;
		}
	}

	printf("%d\n", ans);

	return 0;
}