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
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 200000


int main(){
	int n, k, x;
	scanf("%d", &n);
	x = 1;
	while (n > 3){
		k = n / 2;
		k = n - k;
		f(i, k){
			printf("%d ", x);
		}
		x = x * 2;
		n = n / 2;
	}
	if (n == 3){
		printf("%d %d %d\n", x, x, x * 3);
	}
	else if (n == 2){
		printf("%d %d\n", x, x * 2);
	}
	else printf("%d\n", x);



	return 0;
}