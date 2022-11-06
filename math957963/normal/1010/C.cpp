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

int gc(int x, int y){
	if (x > y)swap(x, y);
	if (x == 0)return y;
	y = y%x;
	return gc(y, x);
}


int main(){
	int n, k;
	int x;
	int g;
	vector<int>a;
	scanf("%d %d", &n,&k);
	g = k;
	f(i, n){
		scanf("%d", &x);
		x = x%k;
		g = gc(x, g);
	}
	x = 0;
	printf("%d\n", (k/g));
	f(i, (k/g)-1){
		printf("%d ", x);
		x += g;
	}
	printf("%d\n", x);
	
	return 0;
}