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
#define N 100001


int main(){
	int a[N];
	int b[N];
	f(i, N){
		a[i] = 0;
		b[i] = 0;
	}
	int n, k;
	int x, c;
	k = 3;
	scanf("%d %d", &n,&c);
	f(i, n){
		scanf("%d", &x);
		if (a[x] > 0)k = 0;
		if (b[x] > 0 && k > 1)k = 1;
		if (k > 1 && a[(x&c)]>0)k = 1;
		if (k > 2 && b[(x&c)]>0)k = 2;
		a[x]++;
		b[(x&c)]++;
	}


	if(k>2)printf("-1\n");
	else printf("%d\n",k);


	return 0;
}