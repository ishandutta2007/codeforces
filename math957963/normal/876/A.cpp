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
	int n, k;
	int x, y, z;
	int ans = 0;

	scanf("%d", &n);
	scanf("%d", &x);
	scanf("%d", &y);
	scanf("%d", &z);
	k = 1;
	f(i, n-1){
		if (k == 1){
			if (x < y){
				ans += x;
				k = 2;
			}
			else{
				ans += y;
				k = 3;
			}
		}
		else if (k == 2){
			if (x < z){
				ans += x;
				k = 1;
			}
			else{
				ans += z;
				k = 3;
			}
		}
		else{
			if (y< z){
				ans += y;
				k = 1;
			}
			else{
				ans += z;
				k = 2;
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}