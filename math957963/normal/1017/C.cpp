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
	int a[N];
	int n, k;
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	f(i, 1000){
		if ((i*i) >= n){
			z = i;
			break;
		}
	}

	f(i, z){
		x = (z - i - 1)*z;
		x++;
		y = (z - i)*z;
		if (y > n)y = n;
		for (int j = x; j <= y; j++){
			printf("%d", j);
			if (j == z)printf("\n");
			else printf(" ");
		}
	}

	return 0;
}