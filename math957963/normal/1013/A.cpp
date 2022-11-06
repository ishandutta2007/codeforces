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
	int n;
	int x, y, z;
	y= 0;
	z = 0;
	scanf("%d", &n);
	f(i, n){
		scanf("%d", &x);
		y += x;
	}

	f(i, n){
		scanf("%d", &x);
		z += x;
	}

	if(y>=z)printf("Yes\n");
	else printf("No\n");


	return 0;
}