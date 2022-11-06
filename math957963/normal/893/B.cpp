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
	int n;
	int ans = 1;
	int a[15];
	int b[15];
	b[0] = 1;
	scanf("%d", &n);
	f(i, 12)b[i + 1] = b[i] * 2;
	f(i, 12)a[i + 1] = b[i] * (b[i + 1] - 1);
	for (int i = 11; i >= 1; i--){
		if (n%a[i] == 0){
			ans = a[i];
			break;
		}
	}
	printf("%d\n", ans);

	return 0;
}