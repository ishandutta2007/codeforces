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
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 200000


int main(){
	int a[N];
	f(i, N)a[i] = 0;
	int n, k;
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d %d", &n,&k);
	f(i, k){
		scanf("%d", &a[i]);
	}
	x = 0;
	if (n % 2 == 0)x = a[k-1] % 2;
	else{
		f(i, k){
			x = (x + a[i]) % 2;
		}
	}

	if(x%2==1)printf("odd\n");
	else printf("even\n");


	return 0;
}