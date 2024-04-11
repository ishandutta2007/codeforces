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
	char a[N + 1];
	f(i, N + 1)a[i] = 0;
	int n, k;
	int x, y;
	scanf("%s", a);
	n = strlen(a);
	f(i, n){
		a[n + i] = a[i];
	}
	x = 1;
	y = 1;
	f(i, 2 * n-1){
		if (a[i] != a[i + 1]){
			x++;
			if (x > y)y = x;
		}
		else{
			x = 1;
		}
	}
	if (y > n)y = n;
	printf("%d\n", y);


	return 0;
}